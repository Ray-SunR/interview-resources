class Math
{
	int div(int x,int y) throws Exception
	{
		return x / y;
	}
};


class ExceptionDemo
{
	public static void main(String[] args)
	{
		Math m = new Math();
		try
		{
			m.div(1,0);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
