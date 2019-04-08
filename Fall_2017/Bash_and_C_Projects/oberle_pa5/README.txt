***General Notes for Deater Project (Part 1) ***
    Overview:
        - Program allows for up to 200 command-line arguments to be entered
          (Min. number of arguments: 2, program name included)
        - Program takes all command-line arguments and adds any integer arguments
          and displays their sum (provided there were integers sent as arguments)
        - If arguments are strings/character the programs determines if a given
          argument is a substring of any future string argument

    Execution:
        - Example Run of Program:
            deater 1 2 3 4 5 dog cat catdog dogc

        - Output of Sample:
            Sum of intergers: 15
            dog is a substring of catdog
            dog is a substring of dogc
            cat is a substring of catdog
        
***General Notes for Phone Number Project (Part 2) ***
    Overview:
        - Programs allows for a single string of up to a length of 200 to be entered
          (string can include characters, integers, and symbols)
        - Program looks through the entered string for the first 10 intergers
          These 10 integers are converted into a phone number format 
        - If there are less then 10 integers in the string an error message is displayed

    Execution:
        - Example Run of Program:

            phone
            Enter up to 200 integers/character/etc. to create a phone number.
            There must be at least 10 integers entered.
            INPUT: ger314htgre576ewf12#@3ds4feriojaf4865er486asdf468 

        - Output of Sample:
            (314)576-1234
