class Inventory implements Runnable
{
	private int NumOfTickets;
	public Inventory()
	{
		NumOfTickets = 10;
	}
	public synchronized void Sell()
	{       
		if (NumOfTickets > 0)
		{
			--NumOfTickets;
			System.out.println("A ticket sold!" + NumOfTickets + " left." + " Sold by: " + Thread.currentThread().getName());
		}
	}
	public void run()
	{
		synchronized (this)
		{
			while (NumOfTickets > 0)
			{
				try
				{
					Thread.sleep(1000);
				}
				catch (Exception e) {System.out.println(e);}
				Sell();
			}
		}
	}
};

class People extends Thread
{
	private String name;
	Inventory i;
	public People(Inventory i,String name)
	{
		super(i,name);
	}
	public String getPeopleName()
	{
		return name;
	}
}

class ThreadDemo
{
	public static void main(String[] args)
	{
		Thread t = Thread.currentThread();
		System.out.println(t.getName() + t.isInterrupted());
		t.interrupt();
		System.out.println(t.getName() + t.isInterrupted());
		System.out.println(t.getName() + t.isAlive());
		try
		{
			t.sleep(2000);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println(t.getName() + t.isInterrupted());	
		Inventory i = new Inventory();
		People p1 = new People(i,"Renchen Sun");
		People p2 = new People(i,"Yuchen Liu");
		People p3 = new People(i,"Lucy Du");
		People p4 = new People(i,"Helena");
		p1.start();
		p2.start();
		p3.start();
		p4.start();
	}
}
