# We assume that the user executes this from graph-tests-2 root
data <- read.csv("./data/results.csv",sep=",")

# Function definitions
data2list <- function(csvRow) {
	datalist <- c()
		for (x in data[csvRow,3:202]) { # Unfortunately, data currently lives in columns 3-202 of the csv file :(
			datalist <- c(datalist, x)
		}
	return(datalist)
}

tidyResults <- function(dataName,data) {
	print(paste0("Results for: ", dataName, ": mean: ", mean(data), " sd: ", sd(data)))
}

# Data by algorithm, graph type and graph size
bfsL64 <- data2list(3)
dijkstrL64 <- data2list(4)
bfsM64 <- data2list(5)
dijkstrM64 <- data2list(6)

bfsL128 <- data2list(10)
dijkstrL128 <- data2list(11)
bfsM128 <- data2list(12)
dijkstrM128 <- data2list(13)

bfsL512 <- data2list(17)
dijkstrL512 <- data2list(18)
bfsM512 <- data2list(19)
dijkstrM512 <- data2list(20)

# Results
tidyResults("bfsL64",bfsL64)
tidyResults("dijkstrL64",dijkstrL64)
tidyResults("bfsM64",bfsM64)
tidyResults("dijkstrM64",dijkstrM64)

tidyResults("bfsL128",bfsL128)
tidyResults("dijkstrL128",dijkstrL128)
tidyResults("bfsM128",bfsM128)
tidyResults("dijkstrM128",dijkstrM128)

tidyResults("bfsL512",bfsL512)
tidyResults("dijkstrL512",dijkstrL512)
tidyResults("bfsM512",bfsM512)
tidyResults("dijkstrM512",dijkstrM512)
