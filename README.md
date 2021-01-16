# PLAIT-AnonApp

PLAIT: Phenotyping Lymphoma with an Artificial Intelligence Toolbox <br>

This anonymization tool is running locally on your computer. PLAIT servers are not involved in the anonymization process. Please, use this tool - PLAIT does not want nor is PLAIT authorized to process sensitive, personal data! <br>

Requirements: R > 3.6 and various shiny-related packages (see below) <br>
Recommended: R 4.0.3 and R-Studio 1.33

```{r}
# uncomment the following package installation commands, if needed
# install.packages('digest')
# install.packages('shiny')
# install.packages('shinyjs')
# install.packages('shinyFeedback')
# install.packages('shinyFiles')
library(digest)
library(shiny)
library(shinyjs)
library(shinyFeedback)
library(shinyFiles)
library(Rcpp)

# replicate this repository on your local machine
# anonymization mechanism always runs locally - on your machine!
# no sensitive data are being uploaded to our servers!
shiny::runGitHub("PLAITAnonApp", "Wandergarten", subdir = "R")
```
After this, a new window should pop-up: <br>

![New Window](https://raw.githubusercontent.com/Wandergarten/PLAIT-AnonApp/main/howto/1a.png)

Click on the Button "Choose File", this will prompt your file explorer. Choose the file you would like to anonymize by marking and selecting it. If you'd like to try it out, this package comes with three sample .LMD files in the folder [/Sample/](https://github.com/Wandergarten/PLAIT-AnonApp/tree/main/sample).

![Choose File](https://raw.githubusercontent.com/Wandergarten/PLAIT-AnonApp/main/howto/1b.png)

After you have selected your lymphoma dataset (.LMD/.FCS), confirm your wish to irreversibly anonymize this file. It may be recommended, creating a backup of you file in another location of your computer's directory. To avoid this, give your file another name with the same file type extension.

![New File Name](https://raw.githubusercontent.com/Wandergarten/PLAIT-AnonApp/main/howto/2.png)

Now, you are all set to let the Anonymization tool do its work: Click on the button "Anonymize"

![Anonymize](https://raw.githubusercontent.com/Wandergarten/PLAIT-AnonApp/main/howto/3.png)


Note that this is a student project!

For inquiries and feedback, contact: databionics@informatik.uni-marburg.de <br>
Project lead: Prof. Ultsch, Dr. rer. nat. MC Thrun, Dr. med. Brendel <br>
Authors and contributors: F. Lerch, J. Schulz-Marner, AC Rathert, C. Kujath 
