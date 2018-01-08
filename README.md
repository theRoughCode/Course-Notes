# Course-Notes
Hey everyone!  This repo was created initially for me to study/increase the lifespan and legacy of my notes.  However, I realized that I could go further and make this open-source.  So, here it is!

## How Do I Contribute?
 If you find a typo or an error or if you have suggestions on something to add, you can:
 1. Check the [issue tracker](https://github.com/theRoughCode/Course-Notes/issues) to make sure that it hasn't been logged already.  If not, create a [new issue](https://github.com/theRoughCode/Course-Notes/issues/new) and someone else can pick it up!
 2. [Fork the repo](https://help.github.com/articles/fork-a-repo/) following the instructions below and submit a pull request with the change!
 
### Forking The Repo
If you found an issue you can fix or implement, you should contribute directly to the code base!
1. Fork this repo.
2. Create a branch with a descriptive name.  For example, if you're fixing issue #5:<br />
```git checkout -b 5-fix-styling-for-math-146```
3. If you're creating a new course, create a new file "courses/\<subject in lower-case\>\<course-number\>.html"
4. Implement your feature.  Don't be afraid to ask questions!
5. Once you've finished implementing your changes, make sure that your master branch is up-to-date with the remote master branch
```
git remote add upstream git@github.com:theroughcode/Course-Notes.git
git checkout master
git pull upstream master
```
6. Update your feature branch with your master branch.
```
git checkout 5-fix-styling-for-math-146
git rebase master
git push --set-upstream origin 5-fix-styling-for-math-146
```
7. Create a [pull request](https://github.com/theRoughCode/Course-Notes/pulls)
8. Your PR will be merged once a project maintainer approves it and merges it!

## What Should I Take Note Of?
### Math-Related Courses
For math-related courses, we will be making use of [MathJax](https://www.mathjax.org/) to embed LaTeX into our html.  
If you are creating a new html file that requires MathJax, include the following script tags into the \<head\> of your document.
```html
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}
  });
</script>
```
#### Tips for MathJax
 - To in-line LaTeX: use $\<math\>$
 - To centre on page (equation-style): use $$\<math\>$$
### CS-Related Courses
For CS-related courses, we will be using Google's [Code-Prettify](https://github.com/google/code-prettify) to format and provide syntax highlighting for our code.  To embed it in your code, use either ```<pre>``` or ```<code>``` with ```class="prettyprint"``` and enclose your code segment in it.

## Contributors [![All Contributors](https://img.shields.io/badge/all_contributors-5-orange.svg?style=flat-square)](#contributors)
<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
| [<img src="https://avatars1.githubusercontent.com/u/3231840?v=4" width="100px;"/><br /><sub><b>Clayton Halim</b></sub>](https://github.com/clayton-halim)<br />[💻](https://github.com/theRoughCode/Course-Notes/commits?author=clayton-halim "Code") | [<img src="https://avatars1.githubusercontent.com/u/20635630?v=4" width="100px;"/><br /><sub><b>Anamaya Garodia</b></sub>](https://github.com/anamayagarodia)<br />[💻](https://github.com/theRoughCode/Course-Notes/commits?author=anamayagarodia "Code") | [<img src="https://avatars1.githubusercontent.com/u/18239310?v=4" width="100px;"/><br /><sub><b>Tate Lok-Chun Cheng</b></sub>](https://github.com/tate1010)<br />[💡](#example-tate1010 "Examples") | [<img src="https://avatars0.githubusercontent.com/u/19877964?v=4" width="100px;"/><br /><sub><b>Hassaan Sami</b></sub>](https://github.com/hsami10)<br />[🐛](https://github.com/theRoughCode/Course-Notes/issues?q=author%3Ahsami10 "Bug reports") | [<img src="https://avatars0.githubusercontent.com/u/5943822?v=4" width="100px;"/><br /><sub><b>Domingo</b></sub>](https://github.com/domingohui)<br />[💻](https://github.com/theRoughCode/Course-Notes/commits?author=domingohui "Code") |
| :---: | :---: | :---: | :---: | :---: |
<!-- ALL-CONTRIBUTORS-LIST:END -->
