#include "IntVector.h"

IntVector::IntVector(){
    _capacity = 0;
    _size = 0;
    _data = nullptr;
}
IntVector::IntVector(unsigned capacity, int value){
    _capacity = capacity;
    _size = capacity;
    _data = new int[capacity];

    for (unsigned int i = 0; i < _size; i++){
        _data[i] = value;
    }
}
IntVector::~IntVector(){
    delete _data;
}
unsigned IntVector::size() const{
    return _size;
}
unsigned IntVector::capacity() const{
    return _capacity;
}
bool IntVector::empty() const{
    return (_size == 0);
}
const int & IntVector::at(unsigned index) const{
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return _data[index];
    }
}
const int & IntVector::front() const{
    return _data[0];
}
const int & IntVector::back() const{
    return _data[_size - 1];
}
int & IntVector::front(){
    return _data[0];
}
int & IntVector::back(){
    return _data[_size - 1];
}
void IntVector::erase(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
        return;
    }
    for (unsigned int i = 0 ; i < _size; i++){
        if (i == index){
            for (unsigned int j = i+1; j < _size; j++){
                _data[j-1] = _data[j];
            }
            break;
        }
    }
    _size--;
}
void IntVector::assign(unsigned n, int value){
    if (n > _capacity){
        if (_capacity * 2 > n + _capacity){
            expand ();
        }
        else{   
            expand (n - _capacity);
        }
    }
    for (unsigned int i = 0 ; i < _size; i++){
        _data[i] = value;
    }
}
void IntVector::push_back(int value){
    if (_size > _capacity){
        expand();
    }
    _size++;
    _data[_size - 1] = value;
}
void IntVector::pop_back(){
    _size--;
}
void IntVector::clear(){
    _size = 0;
}
void IntVector::resize(unsigned n, int value){ //FIXME
    if (n < _size){
        _size = n;
    }
    else if (n > _size){
        if (n > _capacity){
            if (_capacity * 2 > n + _capacity){
                expand();
            }
            else{
                expand(n - _capacity);
            }
            int temp = _size;
            _size = n;
            for (unsigned int i = temp - 1; i < n; i++){
                _data[i] = value;
            }
        }
        else{
            for (unsigned int i = _size - 1; i < n; i++){
                _data[i] = value;
            }
        }
    }
}
void IntVector::reserve(unsigned n ){
    if (n > _capacity){
        expand(n-_capacity);
    }
}
void IntVector::expand(){
    int *newArr;
    if (_capacity != 0){
        _capacity *= 2;
        newArr= new int[_capacity];
        for (unsigned int i = 0; i < _size; i++){
            newArr[i] = _data[i];
        }
        delete[] _data;
        _data = nullptr;

        _data = newArr;
    }
    else{
        delete[] _data;
        _capacity = 1;
        _data = new int[_capacity];
    }
    delete[] newArr;
    newArr = nullptr;
}   
void IntVector::expand(unsigned amount){
    _capacity += amount;
    int *newArr = new int[_capacity];

    for (unsigned int i = 0; i < _size; i++){
        newArr[i] = _data[i];
    }
    delete[] _data;
    _data = nullptr;
    _data = newArr;
     

    delete[] newArr;
    newArr = nullptr;
}
int & IntVector::at(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return _data[index];
    }
}
void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    
    _size ++;
    for (unsigned int i = 0 ; i < _size; i++){
        if (index == i){
            for (unsigned int j = i + 1 ; j < _size; j++){
                _data[j] = _data[j-1];
            }
            _data[index] = value;
            break;
        }
    }
    if (_size+1 > _capacity){
        expand();
    }
}