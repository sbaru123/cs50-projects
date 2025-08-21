import csv
from sys import argv
from collections import Counter


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Program uses 3 command-line argument")
        sys.exit(1)
    else:

        # TODO: Read database file into a variable
        dataFile = open(argv[1], "r")

    # TODO: Read DNA sequence file into a variable
        dnaFile = open(argv[2], "r")

        # print(dataFile.read())

        rows = []
        with open(argv[1], "r") as dataFile:
            reader = csv.DictReader(dataFile)
            headerNames = reader.fieldnames
            for row in reader:
                rows.append(row)

            # print(rows)
            names = []
            for i in range(1, len(headerNames)):
                dnaFile.seek(0)
                match = longest_match(dnaFile.read(), headerNames[i])
                # print("Match:" , match)
                for j in range(len(rows)):
                    # print(rows[j].get(headerNames[i]))
                    if match == int(rows[j].get(headerNames[i])):
                        names.append(rows[j].get("name"))

        name = find_most_common_string(names)

        if names.count(name) == len(headerNames) - 1:
            print(name)
        else:
            print("No match")

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


def find_most_common_string(string_list):
    """
    Finds the most common string in a list of strings.

    Args:
      string_list: A list of strings.

    Returns:
      The most common string in the list. If there's a tie, it returns one of them.
      Returns None if the list is empty.
    """
    if not string_list:
        return None

    # Create a Counter object from the list
    counts = Counter(string_list)

    # Use most_common(1) to get the most frequent element and its count
    # It returns a list of tuples, e.g., [('apple', 3)]
    most_common_element_tuple = counts.most_common(1)

    # Extract the string from the tuple
    most_common_string = most_common_element_tuple[0][0]

    return most_common_string


main()
