/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    bool opt=first < second;
    if(first[curDim] < second[curDim]) {
      return true;
    }
    if(first[curDim] > second[curDim]) {
      return false;
    }
    return opt;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double Psum=findDistance(target,potential);
    double Csum=findDistance(target,currentBest);
    bool opt=potential<currentBest;

    if(Psum<Csum){
      return true;
    }else if(Psum>Csum){
      return false;
    }else{
      return opt;
    }
}

template <int Dim>
double KDTree<Dim>::findDistance(Point<Dim> point1,Point<Dim> point2) const{
  double sum=0;
  for(int i=0;i<Dim;i++){
    sum+=(point1[i]-point2[i])*(point1[i]-point2[i]);
  }
  sum=sqrt(sum);
  return sum;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    points = newPoints;
    root = KDTree_(0, newPoints.size() - 1, 0);
    
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  points = other.points;
  root = KDTree_(0, points.size() - 1, 0);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::KDTree_(int left, int right, int currDim) {
  if(left<0||right<0||left>right){
    return NULL;
  }
  KDTreeNode * subroot = NULL;
  if(left <= right) {
    quickSelect(left, right, (left + right) / 2, currDim);
    subroot = new KDTreeNode(points[(left + right) / 2]);
    subroot->left = KDTree_(left, (left + right) / 2 - 1, (currDim + 1) % Dim);
    subroot->right = KDTree_((left + right) / 2 + 1, right, (currDim + 1) % Dim);
    
  }
  return subroot;
}

template <int Dim>
void KDTree<Dim>::quickSelect(int left, int right, int index, int currDim) {
    if(left==right){
      return;
    }else if (left < right) {
      int i = partition(left, right, (left + right) / 2, currDim);
      if (i > index){
        return quickSelect(left, i - 1, index, currDim);
      }else if (i < index){
        return quickSelect(left + 1, right, index, currDim);
      }else{
        return;
      }
    }
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotI, int currDim) {
  Point<Dim> pivotValue = points[pivotI];
  swap(points[right], points[pivotI]);
  int storeIndex = left-1;
  for(int i = left; i < right; i++) {
    if(smallerDimVal(points[i], pivotValue, currDim)) {
      storeIndex++;
      swap(points[i], points[storeIndex]);
    }
  }
  storeIndex++;
  swap(points[right], points[storeIndex]);
  return storeIndex;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if(this == rhs) {
    return;
  }
  destroy_(root);
  copy_(rhs);
  return *this;
}

template <int Dim>
void KDTree<Dim>::copy_(const KDTree<Dim> &other) {
  this = new KDTree(other);
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  destroy_(root);
}

template <int Dim>
void KDTree<Dim>::destroy_(KDTreeNode *root) {
  if(root) {
    destroy_(root->right);
    destroy_(root->left);
    delete root;
    root = NULL;
  }
} 

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    if(root==NULL){
      return Point<Dim>();
    }
    int strt=0;
    return (findNearestNeighbor_(query,root,strt))->point;
    
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::findNearestNeighbor_(const Point<Dim>& query,typename KDTree<Dim>::KDTreeNode* subroot,int currDim) const{
  KDTreeNode* curr=NULL;
  KDTreeNode* temp=NULL;

  if(subroot->left==NULL && subroot->right==NULL){
    return subroot;
  }

  if(smallerDimVal(query,subroot->point,currDim)==0){
    if(subroot->right){
      curr=findNearestNeighbor_(query,subroot->right,((currDim+1)%Dim));
    }else{
      curr=findNearestNeighbor_(query,subroot->left,((currDim+1)%Dim));
    }
    temp=subroot->left;
    
  }else{
    if(subroot->left){
      curr=findNearestNeighbor_(query,subroot->left,((currDim+1)%Dim));
    }else{
      curr=findNearestNeighbor_(query,subroot->right,((currDim+1)%Dim));
    }
    temp=subroot->right;
    
  }
  if(shouldReplace(query,curr->point,subroot->point)){
    curr=subroot;
  }
  if(abs(query[currDim]-subroot->point[currDim])<=findDistance(query,curr->point)){
    if(temp){
      temp=findNearestNeighbor_(query,temp,((currDim+1)%Dim));
      if(shouldReplace(query,curr->point,temp->point)){
        curr=temp;
      }
    }
  }
  return curr;
}
