  function hide_except(e, type, c, type_but) {

	var a=document.getElementsByClassName(type); 
	 for(i=0; i < a.length; i++) {
	    if (a[i] != e) {a[i].style.display="none";} 
	}

	var b=document.getElementsByClassName(type_but); 
	for(j = 0; j < b.length; j++) {
	    if (b[j] != c) {b[j].style.border="2px solid white";} 
	}	 
  }

  function display(a, type, b, type_but) {
	var e=document.getElementById(a);       /* e est l'élément du document d'identité a */
	var c=document.getElementById(b);
	c.style.border="2px solid #9894f3";
	e.style.display="inline";		/* Applique le style display:inline à l'element d'id a. (affiche) */
	e.style.display="inline";		/* Applique le style display:inline à l'element d'id a. (affiche) */
	hide_except(e, type, c, type_but);                         /* Cache les autres éléments. */
  }
 
