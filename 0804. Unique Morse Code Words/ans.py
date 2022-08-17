class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morseCode = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                     "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
        uniqueCodes = set()
        for word in words:
            # convert the word to morse code
            morseWord = ""
            for i in range(len(word)):
                morseWord += morseCode[ord(word[i]) - 96 - 1]
            uniqueCodes.add(morseWord)
        return len(uniqueCodes)
