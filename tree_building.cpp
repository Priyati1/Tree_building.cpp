#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node*left;
	node*right;
	//constructor
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
node *Build_tree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	else{
		node *root=new node(data);
		root->left=Build_tree();
		root->right=Build_tree();
		return root; 
	}
}
void print_preorder(node *root){
	//base case
	if(root==NULL){
		return ;
	}
	//recursive case
	cout<<root->data<<" ";
	print_preorder(root->left);
	print_preorder(root->right);
}
void inorder(node *root){
	//base case
	if(root==NULL){
		return ;
	}
	//recursive case
	print_preorder(root->left);
	cout<<root->data<<" ";
	print_preorder(root->right);
}
void print_postorder(node*root){
	//base case
	if(root==NULL){
		return ;
	}
	//recursive case
	print_preorder(root->left);
	print_preorder(root->right);
	cout<<root->data<<" ";
}
int count_nodes(node*root){
	//base case
	if(root==NULL){
		return 0;
	}
	//recursive case
	return count_nodes(root->left)+count_nodes(root->right)+1;

}
int height(node*root){//har node ke liye n node traverse kar 
	// rhe hain thus the time complexity is n*n
	//base case
	if(root==NULL){
		return 0;
	}
	//recursive case
	return max(height(root->left),height(root->right))+1;
}
int sum_nodes(node*root){
	//base case
	if(root==NULL){
		return 0;
	}
	//recursive case
	return sum_nodes(root->left)+sum_nodes(root->right)+1;
}
void mirror(node*root){
	if(root==NULL){
		return ;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}
int diameter(node*root){//here we need to reduce the time complexity from n*n to n
	if(root==NULL){
		return 0;
	}
	//if dia is passing throught left subtree
	int opt1=diameter(root->left);
	//if dia is passing throught right subtree
	int opt2=diameter(root->right);
	//if dia is passing throught root node
	int opt3=height(root->left)+height(root->right);
	return max(opt1,max(opt2,opt3));
}
//YEH RUN NHI HUA GIVING SEGMENTATION FAULT AUR SAMJH BHI NHI  AAYA
int pre[]={8,3,1,6,4,7,16,14,13};
int ino[]={1,3,4,6,7,8,16,13,14};
int i=0;
node*create_tree(int s,int e){
	//base case
	if(s>e){
		return NULL;
	}
	//recursive case
	int d=pre[i++];
	node *root=new node(d);
	int j=-1;
	for(int j=s;j<=e;j++){
		if(ino[j]==d){
			break;
		}
	}
	root->left = create_tree(s,j-1);
	root->right = create_tree(j+1,e);
	return root;
}
node*build_tree_levelwise(){
	node *root=NULL;
	int data;
	cout<<"enter the data of root"<<endl;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	root=new node(data);
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node *x=q.front();
		q.pop();
		cout<<"enter the chileder of"<<x->data<<endl;
		int left_child,right_child;
		cin>>left_child>>right_child;
		if(left_child!=-1){
			x->left=new node(left_child);
			q.push(x->left);
		}
		if(right_child!=-1){
			x->right=new node(right_child);
			q.push(x->right);
		}
	}
	return root;
}
 
class Pair{
public:
	int dia;
	int hei;
};
Pair fast_diameter(node *root){
	Pair p;
	//base case
	if(root==NULL){
		p.hei=0;
		p.dia=0;
		return p;
	}
	//recursive case
	Pair left_pair = fast_diameter(root->left);
	Pair right_pair = fast_diameter(root->right);
	p.hei = max(left_pair.hei,right_pair.hei)+1;
	int op1=left_pair.hei+right_pair.hei;
	int op2=left_pair.dia;
	int op3=right_pair.dia;
	p.dia=max(op1,max(op2,op3));
	return p;
}
int main(){
	int n=sizeof(ino)/sizeof(int);
	node *root=create_tree(0,n-1); 
	// node*root=Build_tree();
	// node*root=build_tree_levelwise();
	// cout<<"pre_order"<<endl;
	// print_preorder(root);
	// cout<<endl;
	// cout<<"in_order"<<endl;
	// inorder(root);
	// cout<<endl;
	// cout<<"post_order"<<endl;
	// print_postorder(root);
	// cout<<endl;
	// cout<<"no of nodes"<<":"<<count_nodes(root)<<endl;
	// cout<<"height of tree"<<":"<<height(root)<<endl;
	// cout<<"sum of node"<<":"<<sum_nodes(root)<<endl;
	// cout<<endl; 
	// mirror(root);
	// cout<<"pre_order"<<endl;
	// print_preorder(root);
	// cout<<endl;

	// cout<<"diameter of tree is"<<diameter(root)<<endl;
	// Pair x=fast_diameter(root);
	// cout<<"Diameter"<<":"<<x.dia<<endl;
	// cout<<"height"<<":"<<x.hei<<endl;
	build_tree_levelwise(root); 
	return 0;
}