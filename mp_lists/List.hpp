/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ =0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode*temp;
  while(head_!=NULL){
    temp=head_;
    head_=head_->next;
    free(temp);
  }
  head_=NULL;
  tail_=NULL;
  temp=NULL;
  //length_=0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> prev = NULL;
  if(head_ == NULL){
    head_=newNode;
    tail_=newNode;
    newNode -> next = NULL;
  }else{
    newNode -> next = head_;
    head_->prev=newNode;
  
    if (head_ != NULL) {//fix
      head_=head_->prev;
    }
    
    
    
  }
  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = NULL;
  if(head_ == NULL){
    head_=newNode;
    tail_=newNode;
    newNode -> prev = NULL;
  }else{
    
    newNode -> prev = tail_;
    
    if (tail_ != NULL) {
      tail_ -> next = newNode;
    }
    tail_=tail_ ->next;
    
    
  }
  length_++;

  
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if(length_<splitPoint){
    return head_;
  }
  
  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != NULL; i++) {//
    
    
    curr = curr->next;
  }
  if (curr != NULL) {
      if(curr->prev!=NULL){
        tail_=curr->prev;
        curr->prev->next = NULL;
        curr->prev = NULL;
      }
      
  }

  

  return curr;
  
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  ListNode *curr=head_;
  
  while(curr->next->next!=NULL){
    ListNode *first=curr;
    ListNode *second=curr->next;
    ListNode *third=curr->next->next;
    
    
    if(first->prev!=NULL){
      first->prev->next=second;
    }
    second->prev=first->prev;
    if(third->next!=NULL){
      third->next->prev=first;
    }
    first->next=third->next;
    first->prev=third;
    third->next=first;

    

    if(second->prev==NULL){
      head_=second;
    }
    if(first->next==NULL){
      tail_=first;
      break;
    }else{
      curr=first->next;
    }
  }
  

}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}



/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  
  
  ListNode * temp = NULL;
  ListNode * startPre=startPoint->prev;
  ListNode * endNex=endPoint->next;
  ListNode * startNex=startPoint->next;
  ListNode * endPre=endPoint->prev;
  ListNode * curr = startNex;

  if(startPoint==NULL||endPoint==NULL){
    return;
  }
  startPoint->next=endNex;
  startPoint->prev=startNex;
  endPoint->next = endPre;
  endPoint->prev = startPre;

  while (curr != endPoint) {
    temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;
    curr = temp;
  }
  
  
  
  if(head_!=startPoint){
    startPre->next=endPoint;
  }else{
    head_=endPoint;
  }
  if(tail_!=endPoint){
    endNex->prev=startPoint;
  }else{
    tail_=startPoint;
  }
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  ListNode *start=head_;
  ListNode *end=start;
  if(n<2){
    return;
  }
  while(start!=NULL){
    for(int i=0;i<n-1;i++){
      if(end->next!=NULL){
        end=end->next;
      }else{
        break;
      }
    }
    reverse(start,end);
    start=start->next;
    end=start;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode *list;
  if(first==NULL){
    list=second;
    return second;
  }
  if(second==NULL){
    
    if(first==NULL){
      return NULL;
    }
    list=first;
    return first;
  }
  // if(first==NULL&&second==NULL){
  //     return NULL;
  //   }
  ListNode *currF=first;
  ListNode *currS=second;
  // ListNode *nextF;
  // ListNode *nextS;
  ListNode *temp;
  ListNode *result;
  // ListNode *currF=NULL;
  // ListNode *currF=NULL;
  // ListNode *currF=NULL;
  
  if(currS->data<currF->data){
    result=second;
    
    //head_=second;
    second=second->next;
    //currS=list;
  }else{
    result=first;
    
    //head_=first;
    first=first->next;
    //currF=list;
  }

  // if(second->data < first->data){
  //   temp = second;
  //   second = first;
  //   first = temp;
  //   if(first != NULL){
  //     first->prev = NULL;
  //   }
  // }
  currF=first;
  currS=second; 
  temp=result;
  while(currS!=NULL&&currF!=NULL){
    
    //nextS=currS->next;
    
    //while(currF!=NULL){
      //nextF=currF->next;
      if(currS->data<currF->data){
        
        temp->next=currS;
        currS->prev=temp;
        currS=currS->next;
      }else{
        
        temp->next=currF;
        currF->prev=temp;
        currF=currF->next;
        
      }
      temp=temp->next;
    //}
    // if(currF->next==currS&&currS->prev==currF){
    //   break;
    // }
    //currS=nextS;
    
  }
  if(currF!=NULL){
      temp->next=currF;
      currF->prev=temp;
    }else{
      temp->next=currS;
      currS->prev=temp;
    }
  return result;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  // if(chainLength==1){
  //   start->prev = NULL;
  //   start->next = NULL;
  //   return start;
  // }else{
  //   int brk=chainLength/2;
    
  //   ListNode* temp = start;
  //   for(int i = 1; i <= brk; i++){
  //     temp = temp->next;
  //   }
  //   if (temp != NULL){  //separate the lists
  //     temp->prev->next = NULL;
  //     temp->prev = NULL;
  //   }
  //   //split(brk);
  //   start = mergesort(start, brk);
  //   temp = mergesort(temp, chainLength - brk);
  //   start = merge(start, temp);
  //   return start;



  // if(chainLength == 1) {
  //   return start;
  // }
  // else {
  //   ListNode* firstHalf;
  //   ListNode* secondHalf;
  //   ListNode* temp;
  //   temp = split(start, (chainLength / 2));
  //   firstHalf = mergesort(start, (chainLength / 2));
  //   secondHalf = mergesort(temp, chainLength - (chainLength / 2));
  //   return merge(firstHalf, secondHalf);
  // }
  // return NULL;



  if(chainLength == 1){
    return start;
  }else{
    ListNode *part;
    part=split(start,chainLength/2+chainLength%2);
    ListNode *partF=mergesort(start,chainLength/2+chainLength%2);
    ListNode *partS=mergesort(part,chainLength/2);
    return merge(partF,partS);
  }
  
}


// template <typename T>
// void List<T>::sort() {
//     mergesort(head_,length_);
// }
