##vector
###erase()方法
用于删除vector中的数据，v.erase(iter)删除iter所指向的指针，并且返回下一个元素的指针。
####两种原型：  
	iterator erase(iterator position); 
	iterator erase(iterator first, iterator last);
####两个常见问题：  
	for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++) {
		if( *iter == 3)  
             vec.erase(iter);  
	}
当*iter==3时，erase(iter)方法会删除iter指向的元素，然后iter会成为野指针，iter++就会报错。  

	for(vector<int>::iterator iter=vec.begin();iter!=vec.end();iter++)  
    {  
        if(*iter==x){  
            iter=vec.erase(iter);  
        }  
    }
无法删除连续的两个x，删除第一个x后，iter变为下一个元素的指针，然后iter++跳过第二个x。正确的应该这样：  

	for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); ) {
		if( *iter == 3)
			iter = veci.erase(iter);
		else
			iter ++ ;
	}

