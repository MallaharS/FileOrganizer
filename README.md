# File Organizer

I got tired of folders full of random files piling up, so I wrote this little C++ program to clean them up automatically. You point it at a folder and it sorts everything into subfolders by type — images go with images, PDFs with PDFs, and so on.

## How it works

It checks each file's extension and drops it into the right category folder, making that folder if it doesn't already exist. If it runs into a file type it doesn't know, it just tosses it in an "Other" folder instead of choking on it.

By default it only *previews* what it's going to do — it prints the plan but doesn't actually move anything. You have to flip it to apply mode for it to really move files. I did it that way on purpose, because moving files around is easy to mess up and annoying to undo.

## Running it

```bash
g++ -std=c++20 -o organizer Main.cpp
./organizer
```

Right now it works on a folder called `example_folder`. Easy enough to change in the code if you want it pointed somewhere else.

## What it turns this into

```
example_folder/
├── Image Files/photo.jpg
├── PDF Files/report.pdf
├── Text Files/notes.txt
└── Other/song.mp3
```
