#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

namespace NATLEN {

	namespace DATA_STRUCTURES {
		typedef		const char*		NATLEN_DS_ERR_CODE;
		static NATLEN_DS_ERR_CODE const CIRCULAR_MEMORY_LOOP = "CIRCULAR_MEMORY_LOOP";

		template <typename T>
		class SingleNode {

		public:
			/* Member Functions */
			SingleNode();
			SingleNode(const T);
			SingleNode(const SingleNode<T>&);
			SingleNode(SingleNode<T>&&);
			~SingleNode();
			SingleNode<T>& operator =(const SingleNode<T>&);
			SingleNode<T>& operator =(SingleNode<T>&&) noexcept;
			SingleNode<T>& operator +(SingleNode<T>&);
			
			/* Data Members */
			T*				m_pData;
			SingleNode<T>*	m_pNext;
		};
	}
}

/* ==== FUNCTION DEFINETIONS ==== */

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode() : 
	m_pData{ nullptr },
	m_pNext{ nullptr } {};
	
template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(const T a_data) :
	m_pData{ new T(a_data) },
	m_pNext{ nullptr } {};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(const SingleNode<T>& a_node) :
	m_pData{ nullptr == a_node.m_pData ? nullptr : new T(*a_node.m_pData) },
	m_pNext{ nullptr == a_node.m_pNext ? nullptr : new  SingleNode(*a_node.m_pNext) } {};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::SingleNode(SingleNode<T>&& a_node) :
	m_pData{ a_node.m_pData },
	m_pNext{ a_node.m_pNext } 
{
	a_node.m_pData = nullptr;
	a_node.m_pNext = nullptr;
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>::~SingleNode() 
{
	delete m_pData;
	delete m_pNext;
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>&
NATLEN::DATA_STRUCTURES::SingleNode<T>::operator =(const SingleNode<T>& a_node)
{
	if (this != &a_node) // if not the same object
	{
		//free the about-to-be re-written memory.
		delete m_pData;
		delete m_pNext;

		m_pData = nullptr == a_node.m_pData ? nullptr : new T(*a_node.m_pData);
		m_pNext = nullptr == a_node.m_pNext ? nullptr : new SingleNode(*a_node.m_pNext);
	}
	return *this;
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>&
NATLEN::DATA_STRUCTURES::SingleNode<T>::operator =(SingleNode<T>&& a_node) noexcept
{
	if (this != a_node)// if not the same object
	{
		//free the about-to-be re-written memory.
		delete m_pData;
		delete m_pNext;

		m_pData = a_node.m_pData;
		m_pNext = a_node.m_pNext;
		a_node.m_pData = nullptr;
		a_node.m_pNext = nullptr;
	}
	return *this;
};

template <typename T>
NATLEN::DATA_STRUCTURES::SingleNode<T>&
NATLEN::DATA_STRUCTURES::SingleNode<T>::operator +(SingleNode<T>& a_node)
{
	if (this == &a_node)// if not the same object
	{
		throw CIRCULAR_MEMORY_LOOP;
	}
	//else
	SingleNode<T>* baseNode = new SingleNode(*this);
	SingleNode<T>* connectedNode = new SingleNode(a_node);
	SingleNode<T>* goThrough = baseNode;
	while (nullptr != goThrough->m_pNext)
	{
		goThrough = goThrough->m_pNext;
	}
	goThrough->m_pNext = connectedNode;
	return *baseNode;
};


#endif