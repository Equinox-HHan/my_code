def findPayment(loan, r, m):
    # 请在此添加代码，补全函数findPayment
    #********** Begin *********#
    return loan * (r * (1 + r) ** m) / ((1 + r) ** m - 1)
    #********** End *********#

class Mortgage(object):
     def __init__(self, loan, annRate, months):
        # 请在此添加代码，补全函数__init__
        #********** Begin *********#
        self.loan = loan
        self.months = months
        # Convert annual rate to monthly rate (divide by 100 to convert percentage to decimal, then divide by 12)
        self.rate = annRate / 100 / 12
        self.payment = findPayment(loan, self.rate, months)
        self.paid = [0.0]  # Start with 0 payment at month 0
        self.owed = [loan]  # Initially owe the full loan amount
        #********** End *********#
        self.legend = None

     def makePayment(self):
         # 请在此添加代码，补全函数makePayment
         #********** Begin *********#
         # Add current month's payment to paid list
         self.paid.append(self.payment)
         
         # Calculate interest for the current month
         interest = self.owed[-1] * self.rate
         
         # Calculate principal paid this month
         principal_paid = self.payment - interest
         
         # Calculate new owed amount
         new_owed = self.owed[-1] - principal_paid
         
         # Ensure we don't go negative (last payment might be smaller)
         if new_owed < 0:
             new_owed = 0
         
         # Add new owed amount to owed list
         self.owed.append(new_owed)
         #********** End *********#

     def getTotalPaid(self):
         # 请在此添加代码，补全函数getTotalPaid
         #********** Begin *********#
         # Sum all payments made (excluding the initial 0)
         return sum(self.paid[1:])
         #********** End *********#

     def __str__(self):
        return 'The Mortgage is {self.legend}, Loan is {self.loan}, Months is {self.months}, Rate is {self.rate:.2f}, Monthly payment is {self.payment:.2f}'.format(self=self)

if __name__=="__main__": 
    loan, annRate, months = [float(x) for x in input().split()]
    m1 = Mortgage(loan, annRate, months)
    print(m1)
    m1.makePayment()
    m1.makePayment()
    print('Two months payment is {:.2f}'.format(m1.getTotalPaid()))