#include <iostream>
#include "Replica1.h"

using namespace std;
//Author: Roberto Cordova
//Project: Smart Pointers
//Objective: Use pointers to go out of scope and values end up deleted

int main()
{
	//smart pointers are a wrapper around a regular pointer
	//smart pointers is a general description of a group or type of pointer
	//group consist of unique pointer, shared pointer, weak pointer


	//creating scope with {}
	//{going in scope
	//}going out of scope

	cout << "\nJust exited scope with a unique pointer to replica" << endl;
	{
		//While there are three ways to make this unique pointer
		//this is the safest from exceptions and memory leaks

		unique_ptr<Replica1> replica = make_unique<Replica1>();
		replica->Talk();
	}
	cout << "\nJust exited scope for a unique pointer to replica." << endl;
	cout << endl;
	cout << "About to enter outer scope for a shared pointer to replica." << endl;
	{
		// note declaring
		shared_ptr<Replica1> sharedReplica1;
		cout << "About to enter inner scope for a shared pointer to replica" << endl;
		{
			//shared pointer
			shared_ptr<Replica1> sharedReplica2 = make_shared<Replica1>();
			//assigned a shared pointer to another shared pointer,
			//this will increase the reference count
			//by using a shared pointer to another shared pointer,
			//you are copying it
			//cannot copy a unique pointer
			sharedReplica1 = sharedReplica2;
			sharedReplica1->Talk();
		}
		cout << "\nJust exited inner scope for a shared pointer to replicant." << endl;
	}
	//Notice because shared replica1 finally dies, then the replica dies here
	cout << "\nExited outer scope for a shared pointer to replica." << endl;
	cout << endl;

	cout << "About to enter outer scope for a weaker pointer to replica." << endl;
	{
		weak_ptr<Replica1> weakReplica;
		cout << "Enter inner scope for a weak pointer to replica." << endl;
		{
			//weak pointer
			weak_ptr<Replica1> SharedReplica2 = make_shared<Replica1>();
			//assign weak pointer to another weak pointer
			//will not increase reference count
			//assigning a weak pointer to another shared pointer
			//you are copying it
			//one cannot copy a unique pointer
			weakReplica = SharedReplica2;
			//weakReplica->Talk();
		}
		cout << "\nexited inner scope fpr a weak pointer to replica" << endl;
	}
	cout << "exited outer scope for a weak pointer to replica" << endl;
	cout << endl;

	cout << "\nPress Enter to exit\n";
	cin.get();
	return 0;
	
}//end of main