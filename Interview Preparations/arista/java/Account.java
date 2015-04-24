public class Account
{
	private double balance;
	private static double interestRate;
	public static void main(String[] args)
	{
		Account account = new Account(1000);
		Account account1 = new Account(2000);
		Account.setInterestRate(0.25);
		account.printInterstRate();
		account1.printInterstRate();
		Account.setInterestRate(0.33);
		account.printInterstRate();
		account1.printInterstRate();
		account.withDraw(50);
		account.withDraw(100);
		account.deposit(10);
		account.withDraw(2000);
		CheckingAccount caccount = new CheckingAccount(200);
		caccount.withDraw(100);
		caccount.deposit(50);
	}
	public static void setInterestRate(double rate)
	{
		interestRate = rate;
	}
	public void printInterstRate()
	{
		System.out.println("The interest rate: " + interestRate + "\n");
	}
	public Account(double balance)
	{
		System.out.println("$" + balance + " in the account!");
		this.balance = balance;
	}
	public void deposit(double money)
	{
		System.out.println("$" + money + " Deposited!\n");
		this.balance += money;
		System.out.println("$" + balance + " in the account\n");
	}
	public void withDraw(double money)
	{
		if (money > balance)
			System.out.println("Not enough money to be withdrawn!");
		else
		{
			balance -= money;
			System.out.println("$" + money + " withdrawn from the account!");
			System.out.println("$" + balance + " left in the account!");
		}
	}
}

