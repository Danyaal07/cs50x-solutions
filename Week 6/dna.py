import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("ERROR: Incorrect number of command line arguments")
        sys.exit(1)
    else:
        csvName = sys.argv[1]
        textName = sys.argv[2]

    # Read database file into a variable
    rows = []
    with open(csvName) as file:
        reader = csv.DictReader(file)
        sequences = reader.fieldnames[1:]
        for row in reader:
            rows.append(row)

    # Read DNA sequence file into a variable
    with open(textName) as DNAfile:
        sequence = DNAfile.read().strip()

    # Find longest match of each STR in DNA sequence
    counts = {}
    for STR in sequences:
        counts[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    for person in rows:
        match = True
        for STR in sequences:
            if counts[STR] != int(person[STR]):
                match = False
                break
        if match == True:
            print(person["name"])
    print("No match")


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
