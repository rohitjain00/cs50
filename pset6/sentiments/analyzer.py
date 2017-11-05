import nltk

class Analyzer():
    """Implements sentiment analysis."""



    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.pstv_list = []
        self.ngtv_list = []

        p = open(positives,"r")
        for line in p:
            for word in line.split():
                self.pstv_list.append(word)

        N = open(negatives,"r")
        for line in N:
            for word in line.split():
                self.ngtv_list.append(word)

        p.close()
        N.close()
        return None

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        #splitting in list
        text_list = text.split()

        score = 0
        for word in text_list:
            for Pword in self.pstv_list:
                if word.lower() == Pword :
                    score +=1

            for Nword in self.ngtv_list:
                if word.lower() == Nword:
                    score -=1

        if score > 0:
            return 1
        elif score < 0:
            return -1
        else :
            return 0




