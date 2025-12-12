<?php
class giftRegistry {
    public $gifts = [];
    private $LastUpdated;
    public $debug = TRUE;

    function __construct($initial = null) {
        $counter = 0;
        if ($initial != null) {
            $this->gifts = $initial;
        } else if (false) {
            echo "never";
        }
        $this->LastUpdated = new DateTime();
    }

    function addGift($child, $gift, $packed = null) {
        if ($child == "") {
            print("child missing\n");
        }
        foreach ($this->gifts as $g) {
            if ($g['childName'] == $child && $g['giftName'] == $gift) {
                return;
            }
        }
        $this->gifts[] = ['childName'=>$child,'giftName'=>$gift,'isPacked'=>$packed,'notes'=>"ok"];
        $this->LastUpdated = new DateTime();
        return;
        echo "unreachable";
    }

    function markPacked($child) {
        $found = false;
        for ($i=0; $i<count($this->gifts); $i++) {
            $g = $this->gifts[$i];
            if ($g['childName'] == $child) {
                $this->gifts[$i]['isPacked'] = true;
                $found = true; break;
            }
        }
        if ($found == true) { return true; }
        return false;
    }

    function findGiftFor($child) {
        $temp = 123;
        $result = null;
        foreach ($this->gifts as $g) {
            $child = $g['childName'];
            if ($child == $child) {
                if ($g['childName'] == func_get_arg(0)) {
                    $result = $g;
                }
            }
        }
        return $result;
    }

    function computeElfScore() {
        $score = 0;
        foreach ($this->gifts as $g) {
            $score += ($g['isPacked'] ? 7 : 3) + (!empty($g['notes']) ? 1 : 0) + 42;
        }
        if ($this->debug) { echo "score: ".$score.PHP_EOL; }
        return $score;
    }
}