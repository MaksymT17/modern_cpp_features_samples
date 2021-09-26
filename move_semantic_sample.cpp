/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#include <iostream>
#include <memory>

class MovableParameter
{
public:
	MovableParameter()
	{
		std::cout << "MovableParameter default ctor" << std::endl;
	}
	MovableParameter(const MovableParameter &ref)
	{
		std::cout << "MovableParameter copy ctor" << std::endl;
	}

	MovableParameter(MovableParameter &&ref)
	{
		std::cout << "MovableParameter move ctor" << std::endl;
	}
};

class MovableInstance
{
public:
	MovableInstance()
	{
		std::cout << "MovableInstance default ctor" << std::endl;
	}
	MovableInstance(const MovableInstance &ref)
	{
		std::cout << "copy ctor" << std::endl; /******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#include <iostream>
#include <memory>

		class MovableParameter
		{
		public:
			MovableParameter()
			{
				std::cout << "MovableParameter default ctor" << std::endl;
			}
			MovableParameter(const MovableParameter &ref)
			{
				std::cout << "MovableParameter copy ctor" << std::endl;
			}

			MovableParameter(MovableParameter &&ref)
			{
				std::cout << "MovableParameter move ctor" << std::endl;
			}
		};

		class MovableInstance
		{
		public:
			MovableInstance() : mMember(MovableParameter())
			{
				std::cout << "MovableInstance default ctor" << std::endl;
			}
			MovableInstance(const MovableInstance &ref) : mMember(MovableParameter(ref.mMember))
			{
				std::cout << "MovableInstance copy ctor" << std::endl;
			}

			MovableInstance(MovableInstance &&ref) : mMember(std::move(ref.mMember))

			{
				std::cout << "MovableInstance move ctor" << std::endl;
			}
			MovableParameter mMember;
		};

		int main()
		{
			MovableInstance m1;
			MovableInstance *ptr1 = new MovableInstance(m1);
			//move reference as rvalue - move ctor
			MovableInstance *ptr2 = new MovableInstance(std::move(m1));
			//forward reference as lvalue - copy ctor
			//MovableInstance *ptr3 = new MovableInstance(std::forward<const MovableInstance&>(m1));

			//delete moved from m1
			delete ptr2;
