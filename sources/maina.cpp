
#include <iostream>
class Body
{
    private:
        int z = 9;
    public:
    	int y;	
    void    set(){z = 9;}
    void get(){std::cout << "z = " << z;}
};

class Air : public Body
{
	private:
		int x;
};


int main()
{
// 	Air obj;
// 	Body *b;

// 	b = (Body *)&obj;
// 	*((&b->y) - 1) = 7;
//     b->get();
    Body b;
    *(&(b.y) -1) = 7;
    b.get();
}

// #include <iostream>

// class Air
// {
// 	private:
// 		int x = 5;
//     public:
//         int z = 10;
// };


// int main()
// {
// 	Air *obj;

//     *(&(obj->z) - 1) = 7;
    
// }
