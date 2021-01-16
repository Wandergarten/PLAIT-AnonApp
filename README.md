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

!(alt text) (https://raw.githubusercontent.com/Wandergarten/PLAIT-AnonApp/main/howto/1a.png)


Note that this is a student project!

For inquiries and feedback, contact: databionics@informatik.uni-marburg.de <br>
Project lead: Prof. Ultsch, Dr. rer. nat. MC Thrun, Dr. med. Brendel <br>
Authors and contributors: F. Lerch, J. Schulz-Marner, AC Rathert, C. Kujath 
