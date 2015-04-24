interface USB
{
	void start();
	void stop();
};

class PC
{
	public static void plugin(USB usb)
	{
		usb.start();
		usb.stop();
	}
};

class MP3 implements USB
{
	public void start()
	{
		System.out.println("MP3 starts...");
	}
	public void stop()
	{
		System.out.println("MP3 stops...");
	}
};

class UDisk implements USB
{
	public void start()
	{
		System.out.println("UDisk starts...");
	}
	public void stop()
	{
		System.out.println("UDisk stops...");
	}
};

class UTest
{
	public static void main(String[] args)
	{
		USB ump3 = new MP3();
		USB udisk = new UDisk();
		PC pc = new PC();
		pc.plugin(ump3);
		pc.plugin(udisk);
	}
};
