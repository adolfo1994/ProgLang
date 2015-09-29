
function parent () {
    var parent_var = 0;
    function level1(){
        var l1_var = 1;
        console.log("Parent var: {0}".format(parent_var))
        function level2(){
            var l2_var = 2;
            function level3(){
                var l3_var = 3;
            }
        }

    }
}