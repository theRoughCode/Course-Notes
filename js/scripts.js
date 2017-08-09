$("#menu-toggle").click(function(e) {
    e.preventDefault();
    $("#wrapper").toggleClass("toggled");
});

// animate scrolling to top
$('footer.footer').find('a').click(function() {
    $('body').animate({ scrollTop: 0 });
    return false;
});

// animate scrolling for table of contents
$('div#contents').find('a').click(function(){
    var $href = $(this).attr('href');
    var $anchor = $($href).offset();
    $('body').animate({ scrollTop: $anchor.top });
    return false;
});

// animate scrolling for sidebar
$('ul.sidebar-nav').find('a').click(function(){
    var $href = $(this).attr('href');
    var $anchor = $($href).offset();
    $('body').animate({ scrollTop: $anchor.top });
    return false;
});

// animate scrolling for other links
$('a.link').click(function(){
    var $href = $(this).attr('href');
    var $anchor = $($href).offset();
    $('body').animate({ scrollTop: $anchor.top });
    return false;
});

// update last modified date
const lastMod = document.querySelector('#last_modified');
lastMod.innerHTML = `Last updated on ${document.lastModified}`;

// script for exercises to show solutions
const exercises = document.querySelectorAll('.ex');
exercises.forEach(ex => {
  const btn = ex.querySelector('#exButton');
  const sln = ex.querySelector('#solution');
  btn.innerHTML = 'Show solution';
  sln.style.display = 'none';
  btn.addEventListener('click', function(e) {
    if (sln.style.display === 'none') {
      sln.style.display = 'block';
      btn.innerHTML = 'Hide solution';
    } else {
      sln.style.display = 'none';
      btn.innerHTML = 'Show solution'
    }
  });
});
