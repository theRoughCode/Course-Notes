# Course-Notes
Hey everyone!  This repo was created initially for me to study/increase the lifespan and legacy of my notes.  However, I realized that I could go further and make this open-source.  So, here it is!

## How Do I Contribute?
1. Fork this repo.
2. 
   1. If the course notes for the course you want is already available, just add in the changes to the specific file.
   2. If it isn't created yet, create a new file "\<subject in lower-case\>\<course-number\>.html"
3. Submit a pull request.

## What Should I Take Note Of?
For math-related courses, we will be making use of [MathJax}(https://www.mathjax.org/) to embed LaTeX into our html.  
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
