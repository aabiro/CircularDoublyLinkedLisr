#pragma once
const int DEFAULT_SIZE = 10; 
template <class T> 
	class CircQueue {
		public: 
		CircQueue(unsigned int capacity = DEFAULT_SIZE); 
		// constructor for queue that can hold capacity elements
		~CircQueue();   
		// destructor
		bool isEmpty() const; 
		// returns true if queue is empty, false otherwise 
		bool isFull() const; 
		// returns true if the queue is full, and false otherwise
		void enqueue(T  k); 
		// adds k to end of the queue; 
		// precondition: queue must not be full
		T  dequeue(); 
		// removes the front item from the queue, and returns it; 
		// precondition: queue must not be empty already 
		T  peek() const; 
		// retrieves front item from the queue, and returns it; 
		// precondition: queue must not be empty already
		private: 
		int m_front;        
		// index of front queue element
		int m_size;         
		// number of items currently in queue 
		int m_capacity;  
		// upper capacity of queue 
		T * m_container;      
		// storage for queue items 
	};

template <class T> 
CircQueue<T> ::CircQueue(unsigned int capacity)
{
	m_size = 0;  
	m_front = 0; 
	m_capacity = capacity; 
	m_container = new T[capacity];
} 
template <class T> CircQueue<T> :: ~CircQueue()
{
	delete[] m_container;
}
template <class T>
bool CircQueue<T> ::isEmpty() const
{
	return m_size == 0;
} 
template <class T> 
bool CircQueue<T> ::isFull() const
{
	return m_size == m_capacity;
}
template <class T> void CircQueue<T> ::enqueue(T  k) {
	// precondition: queue must not be full 
	m_container[(m_front + m_size) % m_capacity] = k; m_size++; 
} 
template <class T> T  CircQueue<T> ::dequeue() { 
	// precondition: queue must not be empty already 
	T  item = m_container[m_front]; m_front = (m_front + 1) % m_capacity; 
	m_size--; return item; 
}                 
template <class T> T  CircQueue<T> ::peek() const { 
	// precondition: queue must not be empty already
	return m_container[m_front];
}