<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration {
    public function up(): void {
        Schema::create('magazines', function (Blueprint $table) {
            $table->id(); // bigint, auto-increment, primary key
            $table->string('title', 255);
            $table->unsignedBigInteger('issue_number')->unique(); // unique number(50)
            $table->date('release_date');
            $table->string('topic', 255);
            $table->unsignedBigInteger('publisher_id');
            $table->timestamps();

            // Khóa ngoại liên kết với bảng publishers
            $table->foreign('publisher_id')->references('id')->on('publishers')->onDelete('cascade');
        });
    }

    public function down(): void {
        Schema::dropIfExists('magazines');
    }
};

