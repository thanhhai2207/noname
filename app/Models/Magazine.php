<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;

class Magazine extends Model
{
    use HasFactory;

    protected $fillable = [
        'title',
        'issue_number',
        'release_date',
        'topic',
        'publisher_id',
    ];

    // Đảm bảo rằng release_date là đối tượng Carbon
    protected $dates = [
        'release_date',  // Đảm bảo Laravel hiểu rằng đây là một trường ngày tháng
    ];

    public function publisher()
    {
        return $this->belongsTo(Publisher::class);
    }
}
