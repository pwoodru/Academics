package cpsc2150.banking;

public class Mortgage extends AbsMortgage implements IMortgage {

    private double rate;
    private double cost;
    private double down;
    private int years;
    private ICustomer Customer;
    private final int MAXCREDIT = 850;
    private double Principal;
    private double PercentDown;
    //NumberPaymentNum used for calculating payment in getPayment()
    private static final int NumberPaymentNum = 12;

    /**
     * @param houseCost cost of house
     * @param downPayment customer's chosen down payment
     * @param yearCount years to pay house
     * @param cust the customers name/credentials
     * @requires houseCost >= 0 && downPayment >= 0 && 0 <= yearCount <= MAX_CREDIT_SCORE && cust != ""
     * @ensures cost = houseCost and down = downPayment and years = yearCount and customer = cust
     */
    Mortgage(double houseCost, double downPayment, int yearCount, ICustomer cust) {
        cost = houseCost;
        down = downPayment;
        years = yearCount;
        Customer = cust;
        PercentDown = downPayment / houseCost;
    }

    /**
     *
     * @return true if the loan is approved, false otherwise
     *
     * @post loanApproved iff (Rate*12 < RATE_TOO_HIGH and PercentDown >= MIN_PERCENT_DOWN and DebtToIncomeRatio <= DTOITOOHIGH)
     */
    public boolean loanApproved() {
        if(getRate() >= IMortgage.RATETOOHIGH || PercentDown < MIN_PERCENT_DOWN ||
                ((Customer.getMonthlyDebtPayments() / (Customer.getIncome() / IMortgage.MIN_YEARS)) >= IMortgage.DTOITOOHIGH)){
            return false;
        }
        else{
            return true;
        }
    }

    /**
     *
     * @return the monthly payment on the loan
     *
     * @post getPayment = Payment
     */
    public double getPayment() {
        return (getRate() / NumberPaymentNum) * getPrincipal() / (1 - Math.pow((1 + (getRate()) / NumberPaymentNum),
                - (years * NumberPaymentNum)));
    }

    /**
     *
     * @return the interest rate (apr) for this customer
     *
     * @post getRate = Rate * 12
     */
    public double getRate() {
        rate = BASERATE;

        //Add good rate value if payment is shorter than max years
        if (years < IMortgage.MAX_YEARS) {
            rate = rate + IMortgage.GOODRATEADD;
        }
        //otherwise add normal rate
        else {
            rate = rate + IMortgage.NORMALRATEADD;
        }

        //If down payment % is less than preferred add good rate
        if (PercentDown < IMortgage.PREFERRED_PERCENT_DOWN) {
            rate = rate + IMortgage.GOODRATEADD;
        }
        //If credit score is very bad, add very bad rate
        if (Customer.getCreditScore() < IMortgage.BADCREDIT) {
            rate = rate + IMortgage.VERYBADRATEADD;
        }
        //If credit score is bad but not worst, add bad rate
        if (IMortgage.BADCREDIT <= Customer.getCreditScore() && Customer.getCreditScore() < IMortgage.FAIRCREDIT) {
            rate = rate + IMortgage.BADRATEADD;
        }
        //If credit score is fair but not good, add normal rate
        if (IMortgage.FAIRCREDIT <= Customer.getCreditScore() && Customer.getCreditScore() < IMortgage.GOODCREDIT) {
            rate = rate + IMortgage.NORMALRATEADD;
        }
        //If credit score is good but not great, add good rate
        if (IMortgage.GOODCREDIT <= Customer.getCreditScore() && Customer.getCreditScore() < IMortgage.GREATCREDIT) {
            rate = rate + IMortgage.GOODRATEADD;
        }
        //If credit score is great, don't add a rate
        if (IMortgage.GREATCREDIT <= Customer.getCreditScore() && Customer.getCreditScore() <= MAXCREDIT) {
            rate = rate + 0;
        }

        //return rate after calculations
        return rate;
    }

    /**
     *
     * @return the principal amount of the loan
     * @post getPrincipal = Principal
     */
    public double getPrincipal() {
        Principal = cost - down;
        return Principal;
    }

    /**
     *
     * @return the number of years the loan is for
     * @post getYears = Years
     */
    public int getYears() {
        return years;
    }
}
