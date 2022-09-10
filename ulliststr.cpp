#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
	if(head_ == NULL)
	{
		size_++;
		Item *temp = new Item(); 
  	temp->val[0] = val;
		temp->last = 1;
		head_ = temp;
		tail_ = temp;
		// Item *item = new Item();
		// this->head = 
	}

	else if(tail_->last == 10) //creates a new item to push back into
	{
		size_++;
		Item *temp = new Item(); 
  	temp->val[0] = val;
		temp->last = 1;
		tail_->next = temp;
		temp->prev = tail_;
		temp->next = NULL;
		tail_ = temp;
	}

	else if(tail_->last != 10) //push back normally
	{
		tail_->val[tail_->last] = val;
		tail_->last++;
		size_++;
	}
}

void ULListStr::push_front(const std::string& val)
{
	if(head_ == NULL)
	{
		size_++;
		Item *temp = new Item(); 
  	temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;
		head_ = temp;
		tail_ = temp;
		// Item *item = new Item();
		// this->head = 
	}

	else if(head_->first == 0) //creates new item to push front
	{
		size_++;
		Item *temp = new Item(); 
  	temp->val[9] = val;
		temp->first = 9;
		temp->last = 10;

		head_->prev = temp;
		temp->next = head_;
		temp->prev = NULL;
		head_ = temp;
	}

	else if(head_->first != 0) //push front normally
	{
		head_->val[head_->first-1] = val;
		head_->first--;
		size_++;
	}
}

void ULListStr::pop_back()
{
	if(head_ == NULL)
	{
		return;
	}

 //	tail_->val[tail_->last-1] = NULL;
	tail_->last--;

	if(head_==tail_ && tail_->last==tail_->first) //checks if pop makes the single item empty
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	}
	else if(tail_->last == tail_->first) //deletes item if empty
	{
	tail_ = tail_->prev;
	delete tail_->next;
	tail_->next = NULL;
	}

	size_--;

}

void ULListStr::pop_front()
{
	if(head_ == NULL)
	{
		return;
	}

		//head_->val[head_->first] = NULL;
		head_->first++;
	

	if(head_==tail_ && head_->first == head_->last) //checks if last and only item is empty and deletes
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	}

	else if(head_->first == head_->last) //deletes item if empty
	{
		head_ = head_->next;
		delete head_->prev;
		head_->prev = NULL;
	}
	size_--;
}

	/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last-1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	if(head_==NULL) //if no items exist returns null
	{
		return NULL;
	}

	Item *temp = NULL; 
	temp = head_;
	
	unsigned int i = 0;
	
	for(i = head_->first; loc != 0; loc--) //counts down number of moves from start based on index of location
	{
		if(loc == 0)
		{
			break;
		}

		// if(loc == 0)
		// {
		// 	return &(temp->val[i]);
		// }

		if(i == (temp->last)-1)
		{
			i = 0;
			temp = temp->next;
		}
		
		else
		{
			i++;
		}
	}
	return &(temp->val[i]);
}
	


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
