# PLAIT-AnonApp

```{r}
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

list.of.packages <- c("digest", "shiny", "shinyjs", "shinyFeedback", "shinyFiles", "Rcpp", "fs")
new.packages <- list.of.packages[!(list.of.packages %in% installed.packages()[,"Package"])]
if(length(new.packages)) install.packages(new.packages)


shiny::runGitHub("PLAITAnonApp", "Wandergarten", subdir = "R")
```

Note that this is a student project!

For inquiries and feedback, contact: databionics@informatik.uni-marburg.de \s\s
Project lead: Prof. Ultsch, Dr. rer. nat. MC Thrun, Dr. med. Brendel \s\s
Authors and contributors: F. Lerch, J. Schulz-Marner, AC Rathert, C. Kujath 
