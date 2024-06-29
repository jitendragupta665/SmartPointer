#include <iostream>
using namespace std;

template<typename T>
class UniquePointer {

private:
	T* ptr;

public:
	explicit UniquePointer(T* a) {
		ptr = a;
	}

	UniquePointer(const UniquePointer&) = delete;
	UniquePointer& operator =(const UniquePointer&) = delete;

	UniquePointer(UniquePointer&& up) noexcept {
		ptr = up.ptr;
		up.ptr = nullptr;
	}

	UniquePointer& operator = (UniquePointer&& up) {
		if (this != &up) {
			delete ptr;
			ptr = up.ptr;
			up.ptr = nullptr;
		}
		return *this;
	}

	T& operator *() {
		return *ptr;
	}

	T* operator ->() {
		return ptr;
	}

	~UniquePointer() {
		cout << "Destructor is called"<<endl;
		delete ptr;
	}
};
int main()
{
UniquePointer<int> ptr(new int(5));
UniquePointer<int > ptr2 = move(ptr);
unique_ptr<int> ptr3(new int(6));
unique_ptr<int> ptr4 = make_unique<int>(68);

cout << &ptr2 <<" "<<*ptr3<<" "<< * ptr4 << endl;
}