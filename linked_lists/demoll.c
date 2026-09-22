array vs linked list?
array size is fixed: should be initialized at compile time and cannot be modified
at runtime; linked list size can be varied; 
its easy to traverse array with time complexity O(1) 
since its easy to access its members via indexing where as 
linked list traversal takes O(n) since we need to traverse from head node 
to the intersted node; 

insertion/deletion in linked list is easy using node traversal; 
insert/delete a element in array is difficult due to moving elements; 

why linked list is important in embedded?
any OS rtos, linx kernel....each node stores information of task lists, etc
queues maintained in linux kernel/rtos which is developed using linked list;
tasks waiting for sempahores are in the background waiting in a data structure
linked list form; 

benefits from array?
