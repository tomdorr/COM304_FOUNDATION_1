
# Foundation Computing Course (COM403) 2024

## Introduction
Welcome to the tutorial material for Solent University Foundation Computing module (COM403) 2024.
This module will introduce you to some of the foundations of how computers work.
It is intended to give you a good grounding in computer architecture to prepare for the commencement of a degree in Computing.

The material on this site should be sufficient for you to study on your own and in class. 
Many of the exercises can be done on a PC but to complete all of the material, you will need access to a Raspberry PI (Pi3 or above with a wifi dongle or inbuilt wifi).

For Convenience, some of the exercises use a Raspberry Pi I/O adaptor called a [Gertboard](https://www.amazon.co.uk/Gertboard-Expansion-Board-Raspberry-Assembled/dp/B009SNL3I8).
(If this is unavailable, you can still do the exercises with a bit of ingenuity using alternative I/O adaptors such as [GeeekPi terminal extension](https://www.amazon.co.uk/GeeekPi-Raspberry-Terminal-Breakout-Expansion/dp/B08GKQMC72/).

You can see the contents menu for the module under [sessions](../main/sessions) 

## Getting Started
Fundamentally, software development is a collaborative activity.
Even when you are working on your own project, you will be drawing on examples or library code written by someone else. 

Three of the most important disciplines when working on software projects individually or in teams are 
* Documentation, 
* Project Management, and 
* Version Control.

We want to introduce you to all these practices as part of the Foundation Computing module.

Git is a version control system invented by [Linus Torvalds](https://en.wikipedia.org/wiki/Linus_Torvalds) to help track changes to code during the development of the Linux Kernel.

Git is very powerful and now very widely adopted in the computer industry, supplanting tools which were previously widely used such as [Subversion](https://subversion.apache.org/) and [CVS](https://www.nongnu.org/cvs/). 

In this module you will learn some basic commands and practices to use Git effectively.

[Github.com](https://github.com/) (now owned by Microsoft) provides a comprehensive set of free online tools for collaboratively managing software projects.
GitHub hosts online version control, issue management and project management tools. 

You will use Github to document your work, project manage your tasks and store your code for this module.

To use any of these tools, you will need to set up a personal Github account. 
Your Github account will be used by you for all the work you do during your university career.
It will become like a living CV of the projects you have worked on.

We will cover setting up Git in [Session 1](../main/sessions/session1).

## Using this Github material

Having set up your own Github account, you will then `fork` this module repository which just means creating a clone (or copy) of this repository in your own Github account.

Forking the upstream repository into your account will allow you to maintain your own record of work based upon the tutorial material.

---
**NOTE**

* Your personal work in your repository will be part of the assessment.

---

Forking the upstream repository will allow your tutor to continue to work on their `upstream` copy of the material while you can work separately on your own copy.

If any changes are `committed` upstream by the tutor, you can `merge` those changes into your local repository and use them in your own work. 
You can also use this as a method for getting the example code onto your raspberry pi.

We will cover the merging process in [Session 2](../main/sessions/session2).

To make merging easier, this repository is organised in three separate sections.

* Sessions
* myPracticeCourseWork,
* workup

[Sessions](../main/sessions) Contains the tutorial material for each session.

This is where the tutorials and examples for each week will be created and updated each week.
PLEASE do not change material here as it will be updated each week and you will have difficulty merging any upstream changes with your own work.

Instead COPY each session's material into your own [myPracticeCourseWork](../main/myPracticeCourseWork) folder and use and modify it from there.

[myPracticeCourseWork](../main/myPracticeCourseWork) Is your private working folder.

This is where you should create and save your own practice projects.
Your tutor will NEVER overlay new material here so you can commit any of your own work into this folder.
When you `commit` your changes and `push` them to Github, your work in [myPracticeCourseWork](../main/myPracticeCourseWork) will be a permanent record of what you have been working on.

You can also update your [Personal Learning Record](../main/myPracticeCourseWork/personal_learning_record/personal_learning_record.md) in this folder.
A template Personal Learning Record is provided to get you started.

[workup](../main/workup) is your Tutors work in progress folder.

This is where your tutor creates and updates material before publication each week. 
You are welcome to look at stuff here but mostly it is not complete and won't work (yet).
Don't make your own changes here.

See [Session 1](../main/sessions/session1) for more instructions on getting started with git and forking this repository.

## Submitting your assessment
Your assessment will be your personal learning record as written in markdown on github.

Make sure your repository is linked to on the teacher's [2024 Students](../main/2024-students.md)  page

Your online github repo will be the material that is marked but for record keeping, you MUST submit a snapshot of your repository on time on SOL.

**NO ON TIME SUBMISSION = NO MARKS**

You should download a snapshot of your repository as a zip file and rename it to include your name  
e.g something like 

`COM304_FOUNDATION_1-mainGraigGallen.zip`

Submit this file on SOL.

![alt text](../main/docs/images/downloadGithub.png "Figure downloadGithub.png" )

 

