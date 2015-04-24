class Person
{
	private String name;
	private int age;
	public String toString()
	{
		return "Name: " + name + " Age: " + age;
	}
	public boolean equals(Object obj)
	{
		if (!(obj instanceof Person))
			return false;
		Person p = (Person)obj;
		if (this == (Person)obj)
			return true;
		if (this.name == p.name && this.age == p.age)
			return true;
		else
			return false;
	}
	public Person(String name,int age)
	{

		this.name = name;
		this.age = age;
	}
	static class Inner
	{
		public void print()
		{
			System.out.println("Something...");
		}
	}
};


class ObjectTest
{
	public static void main(String[] args)
	{
		Person p1 = new Person("Renchen Sun",21);
		Person p2 = new Person("Yuchen Liu",22);
		Person.Inner in = new Person.Inner();
		in.print();
		System.out.println(p1.toString());	
		System.out.println(p1.equals(p2));
		System.out.println(p1.equals(p1));
		System.out.println(p1.equals("Renchen Sun"));
	}
};
