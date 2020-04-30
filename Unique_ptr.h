template <typename T>
class Unique_ptr
{
public:
    //delete default constuctor,copy constructor and copy assign
    Unique_ptr() = delete;
    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    //constructor
    Unique_ptr(T* ptr);

    //distructor
    ~Unique_ptr();

    //move constructor
    Unique_ptr(Unique_ptr&& rhs);

    //move assign
    Unique_ptr& operator=(Unique_ptr&& rhs);

    T operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }
private:
    T* m_ptr;
};

template <typename T>
Unique_ptr<T>::Unique_ptr(T* ptr)
{
    m_ptr = ptr;
}

template <typename T>
Unique_ptr<T>::~Unique_ptr()
{
    if (m_ptr)
        delete m_ptr;
}

template <typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& rhs)
{
    m_ptr = rhs.m_ptr;
    rhs.m_ptr = nullptr;
}

template <typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr&& rhs)
{
    if (m_ptr)
        delete m_ptr;

    m_ptr = rhs.m_ptr;
    rhs.m_ptr = nullptr;
}

