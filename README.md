# RPSLS_135
## How to compile and run with wxWidgets:
1. Make sure wxWidgets is installed: `wx-config --libs` which should return a list of libraries.
2. `g++ `wx-config --cxxflags` -o out *.cpp `wx-config --libs``
`
`

## How to compile and run the code:
### clone repo to your machine
1. `git clone https://github.com/lastjediluke/RPSLS_135.git`

### change to the directory (folder) where you cloned the repo
2. `cd RPSLS_135`

### open a terminal or command line prompt
### compile the code into an executable called output
3. `g++ *.cpp -o output`

### run the executable
4. `./output`


## How to get to your branch

1. make sure you have a cloned repo on your computer
2. get a terminal open and cd to the directory where the repo is
3. checkout from your branch name
- For example, Luke's branch would be: `git checkout -b luke`
- note that `-b` creates a new branch on your computer
4. get the latest code onto your machine
`git pull origin master`
- sometimes you have to stash changes: `git stash` then do step 4 again
- if there is a merge conflict, hit me up (Luke)
5. start coding!
6. stage changes for a commit (. adds all files in current directory and subdirectories)
`git add .`
7. make a commit (-m is message)
`git commit -m "indicate your changes here"`
- if your code has errors when you push...please let us know
8. push to your branch
`git push origin yourname`
9. Hit Luke up if you think your code will merge
