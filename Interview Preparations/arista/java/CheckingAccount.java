public class CheckingAccount extends Account
{
	public CheckingAccount(double balance) {super(balance);}
	public void cashCheck(double amount) {withDraw(amount);}
}
