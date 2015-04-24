class A
{
	private static final int a;
	private final int b;
	static
	{
		System.out.println("Here is the static block");
		a = 999;
	}
	{
		System.out.println("Here is the non-static initializer");
	}
	public static int getA(){return a;}
	public int getB(){return b;}
	A(){System.out.println("Here is the constructor"); b = 200;}
};


public class Initializer
{
	public static void main(String[] args)
	{
		System.out.println(new A().getB());
		System.out.println(new A().getB());
	}
};
