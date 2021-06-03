package cpsc2150.mortgages;


public class MortgageController implements IMortgageController {
    private IMortgageView view;

    public MortgageController(IMortgageView viewMortgage){
        view = viewMortgage;
    }

    public void submitApplication() {
        double downPayment;
        double houseCost;
        int years;
        double monthlyDebt;
        double yearlyIncome;
        int creditScore;
        String name;
        boolean anotherOne = false;
        boolean anotherMort = false;

        do{
            //reads in the name
            name = view.getName();

            //checks if yearly income input is valid and then calls IMortgageView for printing to user
            do{
                yearlyIncome = view.getYearlyIncome();
                if(yearlyIncome < 0){
                    view.printToUser("Income should be greater than 0.");
                }
            }while(yearlyIncome < 0);

            //checks if monthly debt input is valid and then calls IMortgageView for printing to user
            do{
                monthlyDebt = view.getMonthlyDebt();
                if(monthlyDebt < 0){
                    view.printToUser("Debt must be greater than or equal to 0.");
                }
            }while(monthlyDebt < 0);

            //checks if credit score input is valid and then calls IMortgageView for printing to user
            do{
                creditScore = view.getCreditScore();
                if(creditScore < 0 || creditScore > 850){
                    view.printToUser("Credit score must be greater than 0 and less than 850");
                }
            }while(creditScore < 0 || creditScore > 850);

            //checks if house cost input is valid and then calls IMortgageView for printing to user
            do{
                houseCost = view.getHouseCost();
                if(houseCost < 0){
                    view.printToUser("Cost must be greater than 0.");
                }

            }while(houseCost < 0);

            //checks if down payment input is valid and then calls IMortgageView for printing to user
            do{
                downPayment = view.getDownPayment();
                if(downPayment < 0 || downPayment > houseCost)
                {
                    view.printToUser("Down payment must be greater than 0 and less than the cost of house.");
                }
            } while(downPayment < 0 || downPayment > houseCost);

            //checks if years input is valid and then calls IMortgageView for printing to user
            do{
                years = view.getYears();
                if(years < 0){
                    view.printToUser("Years must be greater than 0.");
                }

            }while(years < 0);
            do{
                ICustomer c = new Customer(monthlyDebt, yearlyIncome, creditScore, name);
                String customerInfo = c.toString();
                view.printToUser(customerInfo);
                IMortgage mort = new Mortgage(houseCost, downPayment, years, c);
                String mortgageInfo = mort.toString();
                view.printToUser(mortgageInfo);

                if(view.getAnotherMortgage()){
                    anotherMort = true;
                    do{
                        houseCost = view.getHouseCost();
                        if(houseCost < 0){
                            view.printToUser("Cost must be greater than 0");
                        }

                    }while(houseCost < 0);
                    do{
                        downPayment = view.getDownPayment();
                        if(downPayment < 0 || downPayment > houseCost)
                        {
                            view.printToUser("Down payment must be greater than 0 and less than the cost of house.");
                        }
                    } while(downPayment < 0 || downPayment > houseCost);
                    do{
                        years = view.getYears();
                        if(years < 0){
                            view.printToUser("Years must be greater than 0.");
                        }

                    }while(years < 0);
                }
            }while(anotherMort);
            if(view.getAnotherCustomer()){
                anotherMort = true;
            }else{
                anotherMort = false;
                System.exit(0);
            }
        }while(anotherMort);
    }
}
