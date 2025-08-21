import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Program uses 3 command-line argument")
        sys.exit(1)
    else:

    # TODO: Read database file into a variable
        dataFile = open(argv[1] , "r")

    # TODO: Read DNA sequence file into a variable
        dnaFile = open(argv[2] , "r")

        #print(dataFile.read())

        rows = []
        with open(argv[1] , "r") as dataFile:
            reader = csv.DictReader(dataFile)
            headerNames = reader.fieldnames
            for row in reader:
                rows.append(row)


                for i in range(1, len(headerNames)):
                    match = longest_match(dnaFile, headerNames[i]):
                    for j in range:
                        if match == rows[j].get("" , headerNames[i]):
        rows[1].get("name")





    # TODO: Find longest match of each STR in DNA sequence
    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
