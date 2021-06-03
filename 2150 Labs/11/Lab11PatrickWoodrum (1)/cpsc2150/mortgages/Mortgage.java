package cpsc2150.mortgages;


/**
 * @Invariants  rate >= 0 and
 *              cost >= 0 and
 *              downs >= 0 and
 *              amountYears >= 0 and
 *              customer != "" and
 *              Principal >= 0 and
 *              PercentDown >= 0
 */
public class Mortgage extends AbsMortgage implements IMortgage {
    double rate;
    double cost;
    double downs;
    int amountYears;
    ICustomer customer;
    private final int MAXCREDIT = 850;
    double Principal;
    double PercentDown;

    /**
     * @param houseCost the cost of the house
     * @param downPayment the customer's downpayment on house
     * @param years the years to pay off
     * @param c the customers name
     * @requires houseCost >= 0 and downPayment >= 0 and 0 <= years <= MAX_CREDIT_SCORE and c != ""
     * @ensures cost = houseCost and downs = downPayment and amountYears = years and customer = c
     */
    Mortgage(double houseCost, double downPayment, int years, ICustomer c) {
        cost = houseCost;
        downs = downPayment;
        amountYears = years;
        customer = c;
        PercentDown = downPayment/houseCost;
    }

    /**
     * @return true or false
     * @requires rate != 0 and customer.getMonthlyDebtPayments() != 0 and customer.getIncome() != 0
     * @ensures loanApproved() = 1 || loanApproved() = 0
     */
    @Override
    public boolean loanApproved() {
        if(getRate() >= IMortgage.RATETOOHIGH || PercentDown < MIN_PERCENT_DOWN || ((customer.getMonthlyDebtPayments() / (customer.getIncome() / IMortgage.YEARS)) >= IMortgage.DTOITOOHIGH)){
            return false;
        }
        else{
            return true;
        }
    }

    /**
     * @return payment of house
     * @requires rate != 0 and Principal != 0 and amount years != 0
     * @ensures getPayment != 0
     */
    @Override
    public double getPayment() {
        return (getRate() / IMortgage.YEARS) * getPrincipal() / (1 - Math.pow((1 + (getRate()) / IMortgage.YEARS), - (amountYears * IMortgage.YEARS)));
    }

    /**
     * @return rate of house
     * @requires amount years != 0 and PercentDown != 0 and rate != 0
     * @ensures rate != 0
     */
    @Override
    public double getRate() {
        rate = BASERATE;
    if(amountYears < IMortgage.MAX_YEARS){
        rate = rate + IMortgage.GOODRATEADD;
    }
    else{
        rate = rate + IMortgage.NORMALRATEADD;
    }

    if(PercentDown < IMortgage.PREFERRED_PERCENT_DOWN){
        rate = rate + IMortgage.GOODRATEADD;
    }
        if (customer.getCreditScore() < IMortgage.BADCREDIT) {
            rate = rate + IMortgage.VERYBADRATEADD;
        }
        if (IMortgage.BADCREDIT <= customer.getCreditScore() && customer.getCreditScore() < IMortgage.FAIRCREDIT) {
            rate = rate + IMortgage.BADRATEADD;
        }
        if (IMortgage.FAIRCREDIT <= customer.getCreditScore() && customer.getCreditScore() < IMortgage.GOODCREDIT) {
            rate = rate + IMortgage.NORMALRATEADD;
        }
        if (IMortgage.GOODCREDIT <= customer.getCreditScore() && customer.getCreditScore() < IMortgage.GREATCREDIT) {
            rate = rate + IMortgage.GOODRATEADD;
        }
        if (IMortgage.GREATCREDIT <= customer.getCreditScore() && customer.getCreditScore() <= MAXCREDIT) {
            rate = rate + 0;
        }
     return rate;
}

    /**
     * @return Principal for the customer
     * @requires Principal != 0
     * @ensures Principal = cost - downs;
     */
    @Override
    public double getPrincipal() {
        Principal = cost - downs;
        return Principal;
    }

    /**
     * @return amount of years for loan
     * @requires years != 0
     * @ensures amountYears = years;
     */
    @Override
    public int getYears() {
        return amountYears;
    }
}
