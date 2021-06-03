package cpsc2150.mortgages;

import java.util.Scanner;

public class MortgageView implements IMortgageView{
    private Scanner read = new Scanner(System.in);
    private IMortgageController control;

    public void setController(IMortgageController c){
        control = c;
    }


    public double getHouseCost() {
        double cost;
        System.out.println("How much does the house cost?");
        cost = read.nextDouble();
        return cost;
    }


    public double getDownPayment() {
        double downPayment;
        System.out.println("How much is the down payment?");
        downPayment = read.nextDouble();
        return downPayment;
    }


    public int getYears() {
        int years;
        System.out.println("How many years?");
        years = read.nextInt();
        return years;
    }


    public double getMonthlyDebt() {
        double monthlyDebt;
        System.out.println("How much are your monthly debt payments?");
        monthlyDebt = read.nextDouble();
        return monthlyDebt;
    }


    public double getYearlyIncome() {
        double income;
        System.out.println("How much is your yearly income?");
        income = read.nextDouble();
        return income;
    }


    public int getCreditScore() {
        int score;
        System.out.println("What is your credit score?");
        score = read.nextInt();
        return score;
    }


    public String getName() {
        String name;
        System.out.println("What's your name?");
        name = read.nextLine();
        return name;
    }


    public void printToUser(String s) {
        System.out.println(s);
    }


    public void displayPayment(double p) {
        System.out.println(p);
    }


    public void displayRate(double r) {
        System.out.println(r);
    }


    public void displayApproved(boolean a) {
        System.out.println(a);
    }


    public boolean getAnotherMortgage() {
        String yOrN;
        System.out.println("Would you like to apply for another mortgage? Y/N");
        yOrN = read.next();
        if(yOrN.equals("N") || yOrN.equals("n")){
            return false;
        }else{
            return true;
        }
    }


    public boolean getAnotherCustomer() {
        String no;
        System.out.println("Would you like to consider another customer? Y/N");
        no = read.next();
        if(no.equals("Y") || no.equals("y")){
            return true;
        }else{
            return false;
        }
    }


}
