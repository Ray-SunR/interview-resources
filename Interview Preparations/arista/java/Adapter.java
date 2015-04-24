interface A
{
	void func1();
	void func2();
	void func3();
};

abstract class B implements A
{
	public void func1(){}
	public void func2(){}
	public abstract void func3();
};

class C extends B
{
	public void func1(){System.out.println("Here is the func1 in B");}
	public void func3(){System.out.println("Here is the func3 in B");}
};

class Adapter
{
	public static void main(String[] args)
	{
		A a = new C();
		a.func1();
		a.func3();
	}
};
