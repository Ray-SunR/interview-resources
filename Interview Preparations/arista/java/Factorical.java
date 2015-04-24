public class Factorical
{
	public static void main(String[] args)
	{
		if (args.length != 0)
		{
			int num = Integer.parseInt(args[0]);
			System.out.println(factorical(num));
		}
		string();
	}
	
	private static int factorical(int num)
	{
		int result = num;
		if (num == 0)
			return result;
		while (num > 1)
		{
			result *= (--num);
		}
		return result;
	}
	private static void string()
	{
		String[] s = {"ABC","BCD","Renchen Sun","Yuchen Liu"};
		String[] temp = new String[10];
		for (int i = 0;i < 10;i++)
			temp[i] = Integer.toString(i);
		String t = new String("HSDKFJSLDJF");
		System.out.println(s[0].toLowerCase());
		System.out.println(s[0]);
		System.out.println(temp[0]);
		System.out.println(temp[1]);
		System.out.println(temp[2]);
		System.out.println(t);
	}
}
