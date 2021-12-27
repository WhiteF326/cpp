class NormalAnswer:
    def __init__(self, day):
        self.day = day
    def __str__(self):
        if self.day < 23:
            return " Eve"
        else:
            return ""

class ExtremelyGoodAnswer:
    def __init__(self, day):
        self.day = day
    def __str__(self):
        if self.day < 24:
            return " Eve" + str(NormalAnswer(self.day))
        else:
            return ""

class SoFuckingGreatSupercalifragilisticexpialidociousAnswerStringGenerator:
    def __init__(self, day):
        self.day = day
    def __str__(self):
        if self.day < 25:
            return " Eve" + str(ExtremelyGoodAnswer(self.day))
        else:
            return ""

class Answer:
    def __init__(self):
        d = int(input())
        self.answerString = "Christmas" + str(SoFuckingGreatSupercalifragilisticexpialidociousAnswerStringGenerator(d))
    def __str__(self):
        return self.answerString

print(str(Answer()))
