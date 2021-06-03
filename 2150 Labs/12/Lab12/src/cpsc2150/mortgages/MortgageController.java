package cpsc2150.mortgages;

public class MortgageController implements IMortgageController{
    private IMortgageView view;

    public MortgageController(IMortgageView v) {
        view = v;
    }

    public void submitApplication()
    {
        double downPayment;
        double houseCost;
        int years;
        double monthlyDebt;
        double yearlyIncome;
        int creditScore;
        String name;
        boolean pass = true;
        boolean approved;

        //Get name of client
        name = view.getName();

        //Yearly Income check, must be greater than 0
        //Retrieving values from the view's helper functions
        yearlyIncome = view.getYearlyIncome();
        if (yearlyIncome < 0) {
            view.printToUser("Yearly income should be greater than 0");
            pass = false;
        }

        //Monthly Debt check, must be greater than or equal to 0
        monthlyDebt = view.getMonthlyDebt();
        if (monthlyDebt < 0) {
            view.printToUser("Monthly debt should be greater than or equal to 0");
            pass = false;
        }

        //Credit Score check, must be greater than 0 and less than 850
        creditScore = view.getCreditScore();
        if (creditScore < 0 || creditScore > 850) {
            view.printToUser("Credit score must be greater than 0 and less than 850");
            pass = false;
        }

        //House Cost check, must be more than 0
        houseCost = view.getHouseCost();
        if (houseCost < 0) {
            view.printToUser("House cost must be greater than 0");
            pass = false;
        }

        //Down Payment check, must be greater than 0 and less than house cost
        downPayment = view.getDownPayment();
        if (downPayment < 0 || downPayment > houseCost) {
            view.printToUser("Down payment must be greater than 0 and less than the cost of house.");
            pass = false;
        }

        //Year check, must be more than 0 years (duh)
        years = view.getYears();
        if (years < 0) {
            view.printToUser("Years must be greater than 0");
            pass = false;
        }

        //Create the customer and mortgage objects
        ICustomer cust = new Customer(monthlyDebt, yearlyIncome, creditScore, name);
        IMortgage m = new Mortgage(houseCost, downPayment, years, cust);
        //Send confirmation to mortgage approval
        approved = m.loanApproved();

        //Display to the user that they have been approved and show them values
        view.displayApproved(approved);
        if (pass){
            view.displayPayment(m.getPayment());
            view.displayRate(m.getRate());
        }
    }
}
