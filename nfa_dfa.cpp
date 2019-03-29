#include<iostream>
#include<bits/stdc++.h>
#define Max 10
using namespace std;

class NFA_States{
private:
    bool final_state,ini_state;
    NFA_States *transition[Max];
    char corrospond_ip[Max];
    int num_trns;
public:
    static int num_ip_set,count_initState,count_FinalState;
    static char *_sigma_;
    NFA_State(){
    	int num_trns=0;
        final_state=false;
        ini_state=false;
        get_Sigma();
    }
   static void get_Sigma();
    void init_val_states();
    void set_Transitions(NFA_States *);
};

void NFA_States::get_Sigma(){
	count_initState=0;
	cout<<"No. of input symbols: ";
	cin>>num_ip_set;
	_sigma_=new char[num_ip_set];
	cout<<"Give the Set of input symbols(e.g.-{0,1}/{a,b,...} : \n";
	for (int i = 0; i < num_ip_set; ++i)
	{
		cout<<"sigma:{\n";
		cin>>_sigma_[i];
		cout<<"}\n";
	}
}
void NFA_States::init_val_states(){
	char choice,ch_final;
	if(count_initState==0){
		cout<<"\nIs this the initial state? (Y/N): ";
		cin>>choice;
		if(choice=='Y' || choice=='y'){
			ini_state=true;
			count_initState=1;
		}
		else{
			ini_state=false;
			count_initState=0;
		}
	}
	cout<<"\nIs this a Final state?(Y/N): ";
	cin>>ch_final;
	if(choice=='Y' || choice=='y'){
		count_FinalState++;
		final_state=true;
	}
	else
		final_state=false;
}

void NFA_States::set_Transitions(NFA_States *obj){
	//int num_trns=0;
	int q_val;
	cout<<"How many transition are taking place from this state?\nA: ";
	cin>>num_trns;
	if(num_trns==0)
		transition[0]=NULL;
	else{
		for(int i=0;i<num_trns;i++){
			cout<<"To State Q:";
			cin>>q_val;
			transition[i]=(obj+q_val);
			cout<<"\nFor corrosponding input(a/b/c/0/1...):";
			cin>>corrospond_ip[i];
		}
	}
}

int main(){
	int num_states;
	cout<<"How many States are there in the NFA? \n A: ";
	cin>>num_states;
	NFA_States *obj=new NFA_States[num_states];
	//NFA_States:: get_Sigma();
	for(int i=0;i<num_states;i++){
		obj[i].init_val_states();
		obj[i].set_Transitions(obj);
	}
	return 0;
}
