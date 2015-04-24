public class Person
{
	private String name;
	private int age;
	public static void main(String[] args)
	{
		Person p1 = new Person("Renchen Sun", 21);
		Person p2 = new Person("Renchen Sun", 21);
		Person p3 = new Person("Yuchen Liu",22);
		if (p1.equals(p2))
			System.out.println("Same Person!");
		else
			System.out.println("Not the same person!");
		if (p1.equals(p1))
			System.out.println("Same Person!");
		else
			System.out.println("Not the same person!");	
		if (p1.equals(p3))
			System.out.println("Same Person!");
		else
			System.out.println("Not the same person!");
		Person p4[] = new Person[10];
		for (int i = 0; i < 10; i++)
		{
			p4[i] = new Person();
		}	
		for (int i = 0; i < 10; i++)
		{
			p4[i].print();
		}
	}
	public Person(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	public Person()
	{
		this.name = "NULL";
		this.age = 0;
	}
	public void print()
	{
		System.out.println("Name: " + this.name);
		System.out.println("Age: " + this.age);
	}
	public boolean equals(Person p)
	{
		if (p == this)
			return true;
		else if (this.name.equals(p.name) && p.age == this.age)
		{
			System.out.println("Same name and same age, but not the same person!");
			return false;
		}
		else
			return false;
	}
};
