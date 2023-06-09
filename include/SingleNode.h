namespace NATLEN {

    namespace DATA_STRUCTURES {

        template <typename T>
        class SingleNode {

            public:

            SingleNode();
            SingleNode(T);
            SingleNode(const SingleNode<T>&);
            ~SingleNode();
            SingleNode(SingleNode<T>&&);
            SingleNode& operator =(const SingleNode<T>&);
            SingleNode& operator +(const SingleNode<T>&);
            SingleNode& operator =(SingleNode<T>&&);
            SingleNode& operator +(SingleNode<T>&&);

            public:

            T*              m_pData;
            SingleNode<T>*  m_pNext;
        };
    }
}