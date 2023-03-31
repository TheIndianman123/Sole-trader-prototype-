#include <stdio.h>
#include <string.h>
#define size 20
#define size2 1 
#define siz2 1

struct salesection
{
    char filename[size];
    float salescost;
    float openingstock;
    float purchases;
    float closingstock;
    float Grossprofit;
};


struct patent
{
    float investment_income;
    float investment_income2;
    float percentage;
    int month1;
    float TB;
    float PWO;

    int years;
};


struct van_at_cost
{
    float vancost;
    int year2;
    float oldvan;
    float newvan;
    int perc;
    int month2;
    int month3;
    float TBVAN;
    float allowance;
    float Accum;
    
};
struct mortgage_interest
{
    float fixedvalue;
    int month4;
    int mortgage_perc;
    float mortageP_L;



};

struct admin
{
    float patentWO;
    float salaries;
    float insurance;
    float dep;
};
struct insuranceAdmin
{
    float insurance;
    float insurance1;
    float insurance2;
};


struct sell_distriput
{
    float lossonsale;
    float dep_van;
    float commission;
};

void sale(struct salesection *sales);
void vancost1(struct van_at_cost *sales3);
void patentscalculate(struct patent *sales2);
void MortgageInt(struct mortgage_interest *sales4);
float insurancevalues(struct insuranceAdmin *sales5);
float display_results( struct salesection *sales,struct van_at_cost *sales3, struct patent *sales2, struct mortgage_interest *sales4,struct insuranceAdmin *sales5);

int main()
{ 
    char name[20];
     printf("\nEnter a name\n");
    fgets(name,20,stdin);
while(1)
{
    int i;
    int option;
    float sales;
    float sales2;
    float sales3;
    float sales4;
    float sales5;
    struct salesection my_sales[10];  // replace 10 with the actual size of your array
    struct van_at_cost my_sales3[10];
    struct patent my_sales2[10];
    struct mortgage_interest my_sales4[10];
    struct insuranceAdmin my_sales5[10];
    
   
    printf("\n[Enter what option you would like]\n(1)[opening Sales]\n(2)[Dep on vehicle]\n(3)[Calculate patent]\n(4)[Insurance]\n(5)[View total]\n[Enter Your option]=");
    scanf("%d",&option);
   
   
   switch(option)
   {
        case 1:
        { 
            struct salesection sales[size2];
            printf("\n------------------[Enter the vales for the sales]---------------\n");
            for(i=0;i<size2;i++)
            {
                printf("\n[%s account]",name);
                printf("\nCost of sales=");
                scanf("%f",&sales[i].salescost);
                printf("\nEnter the opening stock=");
                scanf("%f",&sales[i].openingstock);
                printf("\nEnter the purchases=");
                scanf("%f",&sales[i].purchases);
                printf("\nEnter the closing stock");
                scanf("%f",&sales[i].closingstock);
            }
            sale(sales);
        }
        break;
        case 2:
        {
            struct van_at_cost sales3[size2];
            printf("\n--------[Depreciation on a vehicle]------\n");
            for(i=0;i<size2;i++)
            {
                printf("Dep of old van\n");
                printf("\nEnter the old vehicle present value=");
                scanf("%f",&sales3[i].oldvan);
                printf("Enter how many years did you have it");
                scanf("%d",&sales3[i].year2);
                printf("\n Enter how man months remaining");
                scanf("%d",&sales3[i].month3);
                printf("\nEnter the Allowance recived=");
                scanf("%f",&sales3[i].allowance);
                printf("\nEnter the depreciation percentage=");
                scanf("%d",&sales3[i].perc);
                printf("\nEnter the cost of vehicle from the TB=");
                scanf("%f",&sales3[i].vancost);
                printf("\nEnter the present cost in the TB");
                scanf("%f",&sales3[i].TBVAN);
                printf("\nEnter the value of the New vehicle=");
                scanf("%f",&sales3[i].newvan);
                
                printf("\nEnter the month=");
                scanf("%d",&sales3[i].month2);
            }
            vancost1(sales3);
        }
        break;
        case 3:
        {
            printf("\n\n");
            struct patent sales2[size2];
            //
            printf("\n--------------------------[Calculate the Patent]----------------------\n");
            for(i=0;i<siz2;i++)
            {
                printf("\nEnter the investment value=");
                scanf("%f",&sales2[i].investment_income);
                printf("\nEnter whow long you held the investments");
                scanf("%f",&sales2[i].investment_income2);
                printf("\nEnter the percantage=");
                scanf("%f",&sales2[i].percentage);
                printf("\nEnter the number of months for the investment=");
                scanf("%d",&sales2[i].month1);
                printf("\nEnter the Patents=");
                scanf("%f",&sales2[i].TB);
                printf("Enter the years=");
                scanf("%d",&sales2[i].years);
            }


            patentscalculate(sales2);
            struct mortgage_interest sales4[size2];
            printf("\n--------------------------[Mortage Intrest]-------------------------------\n");
            for(i=0;i<size2;i++)
            {
                printf("\nEnter the Fixed mortgage");
                scanf("%f",&sales4[i].fixedvalue);
                printf("\nEnter the months the Mortage was paid for");
                scanf("%d",&sales4[i].month4);
                printf("\nEnter the percanatge of the fixed value");
                scanf("%d",&sales4[i].mortgage_perc);
                
            }
            MortgageInt(sales4);
        }
        case 4: 
        {

            struct insuranceAdmin sales5[size2];
            struct insuranceAdmin *ptr;
            ptr=&sales5[size2];
            float newinsurancevalue;
            printf("\n--------------[INSURANCE]------------\n");
            for(i=0;i<size2;i++)
            {
                printf("\nEnter The Current insuarance:");
                scanf("%f",&ptr->insurance);
                printf("\nEnter new values to be added on Insurace:");
                scanf("%f",&ptr->insurance1);
                printf("\nEnter the dep on the insurnace:");
                scanf("%f",&ptr->insurance2);
            }
            newinsurancevalue=insurancevalues(ptr);
            printf("\n[New Insurance value]=[%.2f]",newinsurancevalue);

        }
        break;
        case 5:
        {
            float total_sales = display_results(my_sales, my_sales3, my_sales2, my_sales4,my_sales5);  // replace 10 with the actual size of your array
            printf("Total Sales: %.2f", total_sales);
    
        }
        break;
        case 6:
        {
            printf("\nleaving program.....");
            return 0;

        }
       
        break;
        default:
        {
            printf("\nInvalid answer please enter a vaid answer soon");
        }
 
     }  
}
}






        //sales part 
        void sale(struct salesection sales[])
        {
            int i;
            
            float close;
            float purchase;
        
            for(i=0;i<size2;i++)
            {
                sales[i].Grossprofit=(sales[i].salescost-((sales[i].openingstock+sales[i].purchases)-sales[i].closingstock));

            }
            printf("Gross profit= %.2f",sales[i].Grossprofit);
            
        }


        void vancost1(struct van_at_cost *sales3)
        {
            float newvancost=0;
            float month1=0;
            float month2=0;
            int reamin_month;
            float dep_on_old_van1;
            float temp;
            float dep_on_old_van2;
            float totaldep_on_old_van=0.0;
            float profit_loss_workings;
            float profit_loss;
            float AccumTB;
            
            float dep_on_van;
            int i;
            for(i=0;i<size2;i++)
            {
                dep_on_old_van1=sales3[i].oldvan * (sales3[i].perc / 100.0) * sales3[i].year2;
                float dep_on_old_van11=sales3[i].oldvan * (sales3[i].perc / 100.0);
                dep_on_old_van2=dep_on_old_van11 / 12.0 * sales3[i].month3;
                totaldep_on_old_van+=dep_on_old_van1 + dep_on_old_van2;
                printf("Dep on old van=[%.2f]", totaldep_on_old_van);

                profit_loss_workings=sales3[i].oldvan-totaldep_on_old_van;
                if(profit_loss_workings<sales3[i].allowance)
                {
                    profit_loss=profit_loss_workings-sales3[i].allowance;
                    printf("\nLoss=[%.2f]",profit_loss);
                }
                else
                {
                    profit_loss=profit_loss_workings-sales3[i].allowance;
                    printf("\nProfit=[%.2f]",profit_loss);
                }
            }
                for(i=0;i<size2;i++)
            {
                newvancost=(sales3[i].vancost-sales3[i].oldvan)+sales3[i].newvan;
            }
            printf("\n-----------[Dep for vehicle]----------\n");
            for(i=0;i<size2;i++)
            {
                month1=(sales3[i].vancost * sales3[i].perc/100) * sales3[i].month2/12;
                reamin_month=12 - sales3[i].month2;
                month2=(newvancost * sales3[i].perc/100) * reamin_month/12;
                dep_on_van= month1 + month2;
            }
            printf("\nDepreciation on van=[%.2f]",dep_on_van);

            printf("\nAccumulated Deprciation on Vehicle");
            for(i=0;i<size2;i++)
            {
                AccumTB=sales3[i].vancost-sales3[i].TBVAN;
                sales3[i].Accum=(AccumTB + dep_on_van)- totaldep_on_old_van;
            }
            printf("\nThe Accumlated dep is [%.2f]",sales3[i].Accum);

    
}





void patentscalculate(struct patent *sales2)
{
    int i;
    float PATENT[size2];
    
    float TB2;
    float invest=0.0;
    float invest2=0.0;
    
    for(i=0;i<size2;i++)
    {
        invest=((sales2[i].investment_income * (sales2[i].percentage /100)) * sales2[i].month1/12);
    }
    for(i=0;i<size2;i++)
    {
        invest2=((sales2[i].investment_income * (sales2[i].percentage /100)) * sales2[i].investment_income2/12);
        PATENT[i]=sales2[i].TB + invest;
    }
    for(i=0;i<size2;i++)
    {
        sales2[i].PWO=PATENT[i]/sales2[i].years;
        printf("\nInvestments income due=[%.2f]\nInvestment=[%.2f]\nPatent written off=[%.2f]",invest,invest2,sales2[i].PWO);
    }
   

}
void MortgageInt(struct mortgage_interest *sales4)
{
    int i;
    float month4a;
    float month4b;
    

    for(i=0;i<size2;i++)
    {
         month4a=(sales4[i].fixedvalue * (sales4[i].mortgage_perc/100)) * sales4[i].month4/12;
         month4b= (sales4[i].fixedvalue * sales4[i].mortgage_perc)* (12-sales4[i].month4)/12;
         sales4[i].mortageP_L=month4a + month4b;
    }
    printf("\nMortgage interest=[%.2f]",sales4[i].mortageP_L);

}


float insurancevalues(struct insuranceAdmin *ptr)
{
    float total;
    int i;
    printf("\n[The current issurance value]=[%.2f]",ptr->insurance);
    printf("\n[The additonal value]=[%.2f]",ptr->insurance1);
    printf("\n[The dep on insurance]=[%.2f]",ptr->insurance2);
    total=ptr->insurance + ptr->insurance1 + ptr->insurance2;
    return total;
}


float display_results( struct salesection *sales,struct van_at_cost *sales3, struct patent *sales2, struct mortgage_interest *sales4,struct insuranceAdmin *sales5) {
    
    float total;
    // add results from other functions
    for(int i = 0; i < size2; i++) 
    {
        total = sales[i].Grossprofit + sales2[i].PWO + sales3[i].Accum + sales4[i].mortageP_L;

    }

    printf("Total = %.2f", total);
    return total;
}

void adiministration()
{

}
//Selling and Distribution
void sellinganddist()
{

}


