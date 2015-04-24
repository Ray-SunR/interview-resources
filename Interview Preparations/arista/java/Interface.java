interface A
{
	public static final String INFO = "LXH";//equals to String INFO = "LXH"
	public abstract void say();//equals to void say()
};

interface B
{
	String URL = "Here!";
	void hello();
};

interface C
{
	void C();
}

interface D
{
	void D();
}

interface E extends C,D
{
	void E();
}

class Y implements E
{
	public void C()
	{
		System.out.println("C!");
	}
	public void D()
	{
		System.out.println("D!");
	}
	public void E()
	{
		System.out.println("E!");
	}
}

abstract class F
{
	public abstract void fun();
};

class X extends F implements A,B
{
	public void say()
	{
		System.out.println(INFO);
	}
	public void hello()
	{
		System.out.println(URL);
	}
	public void fun()
	{
		say();
		hello();
	}
};

class Interface
{
	public static void main(String [] args)
	{
		/*X x = new X();
		x.say();
		x.hello();
		x.fun();
		Y y = new Y();
		y.C();
		y.D();
		y.E();*/
		A a = new X();
		a.say();
	}
};
